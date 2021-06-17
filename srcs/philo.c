/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swagstaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:14 by swagstaf          #+#    #+#             */
/*   Updated: 2021/06/17 16:05:13 by swagstaf         ###   ########.fr       */
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

int	philo()
{

}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		data = parse_argv(argv, argc);
		if (ft_check_data(data, argc))
			philo(data);
		else
		{
			printf("Not valid params\nYou should enter 4 [5] params:\n");
			printf("number_of_philosophers\ntime_to_die\ntime_to_eat");
			printf("time_to_sleep\n");
			printf("[optional] number_of_times_each_philosopher_must_eat\n");
		}
	}
	return (0);
}
