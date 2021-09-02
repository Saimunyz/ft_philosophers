/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:55 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/02 17:17:29 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO.H
# define PHILO.H

# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_philo
{
	pthread_t		p;
	int				position;
	int				eating;
	int				thinking;
	int				sleeping;
	pthread_mutex_t	left;
	pthread_mutex_t	right;
}				t_philo;

typedef struct s_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_pgilo_must_eat;
}				t_data;

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_check_data(t_data data, int argc);
void			ft_clear_philos(t_philo *philos, int number_of_philos);
t_data			ft_init_data(void);
t_philo			*ft_init_philos(t_data data);

#endif
