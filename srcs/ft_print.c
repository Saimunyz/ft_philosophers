/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:23:14 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/09 22:23:25 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str, t_philo *p)
{
	pthread_mutex_lock(p->print);
	if (p->stop)
	{
		pthread_mutex_unlock(p->print);
		return ;
	}
	printf("%lu %d %s\n", ft_time() - p->start, p->pos, str);
	pthread_mutex_unlock(p->print);
}
