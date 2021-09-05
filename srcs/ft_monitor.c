/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:22:42 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/05 23:11:48 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_is_life(t_philo *p, int num_of_philo)
{
	//long	time;
	int		i;
	int		diff;

	i = 0;
	while (i < num_of_philo)
	{
		if ((diff = ft_time() - p[i].last_eat) >= p[i].time_to_die
			&& p->eating != 1)
		{
			printf("%ld %d died\n", ft_time() - p[i].start, p[i].pos);
			return(1);
		}
		i++;
	}
	return (0);
}

int		ft_check_num_eat(t_philo *philo, int num_of_philo, int num_eat)
{
	int	i;

	i = 0;
	while (philo[i].num_eat > 0 && philo[i].num_eat == num_eat)
	{
		if (i == num_of_philo - 1)
			return (1);
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
		// if (ft_check_num_eat(philo, data->num_of_philo, data->num_of_times_each_pgilo_must_eat))
		// 	return ;
		if (philo[data->num_of_philo - 1].num_eat == data->num_of_times_each_pgilo_must_eat && data->num_of_times_each_pgilo_must_eat > 0)
			return ;
	}
}
