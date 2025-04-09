/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_and_monitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:04:28 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 09:53:50 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init_philo(t_philo *philo, int id, t_data data)
{
	philo->id = id;
	philo->last_meal_time = &data.utils.last_meal_time[id];
	philo->left_fork = &data.mutexes.forks[id];
    philo->right_fork = &data.mutexes.forks[(id + 1) % data.args.numbers_of_philos];
	philo->meal_eaten = &data.utils.meal_eaten[id];
	philo->print_mutex = &data.mutexes.print_mutex;
	philo->stop_mutex = &data.mutexes.stop_mutex;
	philo->stop_simulation = data.utils.stop_simulation;
	philo->time_to_eat = data.args.time_to_eat;
	philo->time_to_sleep = data.args.time_to_sleep;
}

void create_philos(t_data *data)
{
	long i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->args.numbers_of_philos);
	if (!data->philos)
		philos_malloc_error(*data);
	while (i < data->args.numbers_of_philos)
	{
		init_philo(&data->philos[i], i, *data);
		i++;
	}
}

void create_monitor(t_data *data)
{
	data->monitor.last_meal_time = data->utils.last_meal_time;
	data->monitor.meal_eaten = data->utils.meal_eaten;
	data->monitor.meal_mutexes = data->mutexes.meal_mutex;
	data->monitor.meals_to_reach = data->args.meals_to_reach;
	data->monitor.nb_philos = data->args.numbers_of_philos;
	data->monitor.print_mutex = &data->mutexes.print_mutex;
	data->monitor.stop_mutex = &data->mutexes.stop_mutex;
	data->monitor.stop_simulation = data->utils.stop_simulation;
	data->monitor.time_to_die = data->args.time_to_die;
}

void create_philos_and_monitor(t_data *data)
{
	fill_data_with_utils(data);
	create_philos(data);
	create_monitor(data);
}
