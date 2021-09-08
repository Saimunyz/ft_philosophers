/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:55 by swagstaf          #+#    #+#             */
/*   Updated: 2021/09/08 17:36:32 by swagstaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_eat;
	pthread_mutex_t	*forks;
}				t_data;

typedef struct s_philo
{
	pthread_t		p;
	int				pos;
	int				eating;
	int				is_dead;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				num_eat;
	long			start;
	long			last_eat;
	int				left;
	int				right;
	t_data			*data;
	pthread_mutex_t	tool;
}				t_philo;

int				ft_isdigit(char *str);
int				ft_atoi(const char *str);
int				ft_check_data(t_data data, int argc);
void			ft_monitor(t_philo *philo, t_data *data);
long			ft_time(void);
void			ft_clear_philos(t_philo *philos, t_data *data);
t_data			ft_init_data(void);
t_philo			*ft_init_philos(t_data *data);

#endif
