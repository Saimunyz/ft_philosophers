/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:14 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/07 23:20:02 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	parse_argv(int argc, char **argv)
{
	t_data	data;

	data = ft_init_data();
	if (ft_isdigit(argv[1]))
		data.num_of_philo = ft_atoi(argv[1]);
	if (ft_isdigit(argv[2]))
		data.time_to_die = ft_atoi(argv[2]);
	if (ft_isdigit(argv[3]))
		data.time_to_eat = ft_atoi(argv[3]);
	if (ft_isdigit(argv[4]))
		data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (ft_isdigit(argv[5]))
			data.num_eat = ft_atoi(argv[5]);
	}
	return (data);
}

void	ft_print(char *str, t_philo *p)
{
	pthread_mutex_lock(&p->tool);
	if (p->is_dead)
		return ;
	printf("%lu %d %s\n", ft_time() - p->start, p->pos, str);
	pthread_mutex_unlock(&p->tool);
}

void	ft_usleep(int	time)
{
	long	stop;

	stop = ft_time() + (long)time;
	while (ft_time() < stop)
		usleep(0);
}

void	*live(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	p->start = ft_time();
	p->last_eat = p->start;
	while (1 && !p->is_dead)
	{
		pthread_mutex_lock(&p->left);
		ft_print("has taken a left fork", p);
		pthread_mutex_lock(&p->right);
		p->last_eat = ft_time();
		ft_print("has taken a right fork", p);
		p->eating = 1;
		ft_print("is eating", p);
		ft_usleep(p->time_to_eat);
		p->num_eat++;
		pthread_mutex_unlock(&p->left);
		pthread_mutex_unlock(&p->right);
		p->eating = 0;
		ft_print("is sleeping", p);
		ft_usleep(p->time_to_sleep);
		ft_print("is thinking", p);
	}
	return (0);
}

int	philo(t_data data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = ft_init_philos(data);
	if (!philos)
		return (-1);
	while (i < data.num_of_philo)
	{
		pthread_create(&philos[i].p, NULL, live, &(philos[i]));
		pthread_detach(philos[i].p);
		usleep(100);
		i++;
	}
	ft_monitor(philos, &data);
	ft_clear_philos(philos, data.num_of_philo);
	free(philos);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		data = parse_argv(argc, argv);
		if (ft_check_data(data, argc))
		{
			if (philo(data) == -1)
				printf("Malloc error\n");
		}
		else
		{
			printf("Not valid params\nYou should enter 4 [5] params:\n");
			printf("number_of_philosophers\ntime_to_die\ntime_to_eat");
			printf("time_to_sleep\n");
			printf("[optional] number_of_times_each_philosopher_must_eat\n");
		}
	}
	else
		printf("Wrong amount of params\n");
	return (0);
}
