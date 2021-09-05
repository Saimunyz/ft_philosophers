/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:49:30 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/05 23:27:33 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	ft_init_data(void)
{
	t_data	data;

	data.num_of_philo = 0;
	data.time_to_die = 0;
	data.time_to_eat = 0;
	data.time_to_sleep = 0;
	data.num_of_times_each_pgilo_must_eat = 0;
	return (data);
}

int	ft_check_data(t_data data, int argc)
{
	if (data.num_of_philo == 0 || data.time_to_die == 0 ||
		data.time_to_eat == 0 || data.time_to_sleep == 0)
		return (0);
	if (argc == 6)
	{
		if (data.num_of_times_each_pgilo_must_eat == 0)
			return (0);
	}
	return (1);
}

t_philo	*ft_init_philos(t_data data)
{
	t_philo		*philos;
	int			i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data.num_of_philo);
	if (!philos)
		return (NULL);
	while (i < data.num_of_philo)
	{
		pthread_mutex_init(&philos[i].right, NULL);
		if (i != 0)
			philos[i].left = philos[i - 1].right;
		philos[i].pos = i + 1;
		philos[i].thinking = 0;
		philos[i].eating = 0;
		philos[i].sleeping = 0;
		philos[i].num_eat = 0;
		philos[i].time_to_die = data.time_to_die;
		philos[i].time_to_sleep = data.time_to_sleep;
		philos[i].time_to_eat = data.time_to_eat;
		i++;
	}
	philos[0].left = philos[data.num_of_philo - 1].right;
	return (philos);
}

void	ft_clear_philos(t_philo *philos, int number_of_philos)
{
	int	i;

	i = 0;
	while(i < number_of_philos)
	{
		pthread_mutex_destroy(&philos[i].right);
		i++;
	}
}

long	ft_time(void)
{
	struct timeval	tv;
	long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
