/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:49:06 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:17:04 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_mutexes(t_data *data)
{
	long i;

	i = 0;
	data->mutexes.forks = malloc(sizeof(pthread_mutex_t) * data->args.numbers_of_philos);
	if (!data->mutexes.forks)
	{
		write(STDERR_FILENO, "malloc error for forks\n", 23);
		exit(EXIT_FAILURE);
	}
	data->mutexes.meal_mutex = malloc(sizeof(pthread_mutex_t) * data->args.numbers_of_philos);
	if (!data->mutexes.meal_mutex)
		meal_mutex_malloc_error(*data);
	while (i < data->args.numbers_of_philos)
	{
		if (pthread_mutex_init(&data->mutexes.forks[i], NULL))
			forks_init_error(i, *data);
		if (pthread_mutex_init(&data->mutexes.meal_mutex[i], NULL))
			meal_mutex_init_error(i, *data);
		i++;
	}
	if (pthread_mutex_init(&data->mutexes.print_mutex, NULL))
		print_mutex_init_error(*data);
	if (pthread_mutex_init(&data->mutexes.stop_mutex, NULL))
		stop_mutex_init_error(*data);
}
