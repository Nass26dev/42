/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:39:28 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 14:29:33 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data_with_args(t_data *data, int argc, char **argv, int i)
{
	data->philo[i].times.die = ft_atoll(argv[2]);
	data->philo[i].times.eat = ft_atoll(argv[3]);
	data->philo[i].times.sleep = ft_atoll(argv[4]);
	if (argc == 6)
		data->philo[i].meal_required = ft_atoll(argv[5]);
	else
		data->philo[i].meal_required = -1;
}

void	init_mutex(t_philo *philo, t_data *data, int i)
{
	philo->left_fork = &data->forks[i];
	philo->right_fork = &data->forks[(i + 1) % data->nb_philos];
	philo->print_mutex = &data->print_mutex;
	philo->dead_mutex = &data->dead_mutex;
	philo->meal_mutex = &data->meal_mutex;
	philo->time_mutex = &data->time_mutex;
	philo->philo_mutex = &data->philo_mutex;
}

void	create_philos(t_data *data, int argc, char **argv)
{
	int		i;

	i = 0;
	data->is_dead = false;
	while (i < data->nb_philos)
	{
		data->philo[i].id = i + 1;
		init_data_with_args(data, argc, argv, i);
		data->philo[i].last_meal = 0;
		data->philo[i].start_time = 0;
		data->philo[i].meal_count = 0;
		data->philo[i].is_dead = &data->is_dead;
		data->philo[i].nb_philos = data->nb_philos;
		init_mutex(&data->philo[i], data, i);
		data->philo[i].l_fork = &data->bool_forks[i];
		data->philo[i].r_fork = &data->bool_forks[(i + 1) % data->nb_philos];
		*(data->philo[i].l_fork) = false;
		*(data->philo[i].r_fork) = false;
		i++;
	}
}
