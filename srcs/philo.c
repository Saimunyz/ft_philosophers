/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:14 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/02 21:30:25 by swagstaf         ###   ########.fr       */
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
			data.num_of_times_each_pgilo_must_eat = ft_atoi(argv[5]);
	}
	return (data);
}

void	*live(void *philo)
{
	struct timeval	tv;
	t_philo *p;
	int r;
	int	l;

	p = (t_philo *)philo;
	gettimeofday(&tv, NULL);
	l = pthread_mutex_lock(&p->left);
	if (l)
		printf("%d %d has taken a fork\n", tv.tv_usec, p->position);
	r = pthread_mutex_lock(&p->right);
	if (r)
		printf("%d %d has taken a fork\n", tv.tv_usec, p->position);
	if (r && l)
	{
		printf("%d %d is eating\n", tv.tv_usec, p->position);
		p->eating = 1;
		usleep(100);
		p->eating = 0;
	}
	pthread_mutex_unlock(&p->left);
	pthread_mutex_unlock(&p->right);
	printf("%d %d is sleeping\n", tv.tv_usec, p->position);
	usleep(100);
	printf("%d %d is thinking\n", tv.tv_usec, p->position);
	usleep(100);
	if ()
		printf("%d %d died", tv.tv_usec, p->position);
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
		i++;
	}
	ft_clear_philos(philos, data.num_of_philo);
	free(philos);

}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		data = parse_argv(argv, argc);
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
