/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:22:42 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/04 16:42:17 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_is_life(t_philo *philo, int num_of_philo)
{
	long	time;
	long	diff;
	int		i;

	i = 0;
	while (i < num_of_philo)
	{
		time = ft_get_time();
		diff = time - philo[i].last_eat;
		printf("%ld\n", diff);
		if (diff >= philo[i].time_to_die)
		{
			printf("%ld %d died\n", diff, philo[i].position);
			return(1);
		}
		i++;
	}
	return (0);
}

void	ft_monitor(t_philo *philo, t_data *data)
{
	while (1)
	{
		if (ft_check_is_life(philo, data->num_of_philo))
			return ;
	}
}
