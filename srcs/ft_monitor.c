/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:22:42 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/09 01:06:25 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_stop(t_philo *p, int num_of_philo)
{
	int	i;

	i = 0;
	while(i < num_of_philo)
	{
		p[i].stop = 1;
		i++;
	}
}

int		ft_check_num_eat(t_philo *philo, int num_of_philo, int num_eat)
{
	int	i;

	i = 0;
	while (philo[i].num_eat > 0 && philo[i].num_eat >= num_eat)
	{
		if (i == num_of_philo - 1)
		{
			ft_stop(philo, num_of_philo);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_is_life(t_philo *p, int num_of_philo, int time_to_die)
{
	int		i;

	i = 0;
	while (i < num_of_philo)
	{
		if (ft_time() - p[i].last_eat >= time_to_die && p[i].eating != 1)
		{
			ft_stop(p, num_of_philo);
			printf("%ld %d died\n", ft_time() - p[i].start, p[i].pos);
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
		if (ft_check_is_life(philo, data->num_of_philo, data->time_to_die))
			return ;
		if (ft_check_num_eat(philo, data->num_of_philo, data->num_eat))
			return ;
	}
}
