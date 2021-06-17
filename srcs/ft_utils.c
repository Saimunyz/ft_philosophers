/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:49:30 by swagstaf          #+#    #+#             */
/*   Updated: 2021/06/17 16:42:11 by swagstaf         ###   ########.fr       */
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

t_philo	*ft_init_philo(t_data data)
{
	pthread_t	th;
	t_philo		*philos;
	int			i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data.num_of_philo);
	if (!philos)
		return (1); // error
	while (i < data.num_of_philo)
	{

	}
}
