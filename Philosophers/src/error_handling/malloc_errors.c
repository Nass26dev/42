/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:13 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:02:02 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void last_meal_time_malloc_error(t_data data)
{
	long i;

	i = 0;
	while (i < data.args.numbers_of_philos)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	free(data.mutexes.forks);
	free(data.mutexes.meal_mutex);
	pthread_mutex_destroy(&data.mutexes.print_mutex);
	pthread_mutex_destroy(&data.mutexes.stop_mutex);
	write(STDERR_FILENO, "malloc error for last_meal_time\n", 32);
	exit(EXIT_FAILURE);
}

void meal_eaten_malloc_error(t_data data)
{
	long i;

	i = 0;
	while (i < data.args.numbers_of_philos)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	free(data.mutexes.forks);
	free(data.mutexes.meal_mutex);
	free(data.utils.last_meal_time);
	pthread_mutex_destroy(&data.mutexes.print_mutex);
	pthread_mutex_destroy(&data.mutexes.stop_mutex);
	write(STDERR_FILENO, "malloc error for meal_eaten\n", 28);
	exit(EXIT_FAILURE);
}

void philos_malloc_error(t_data data)
{
	long i;

	i = 0;
	while (i < data.args.numbers_of_philos)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	free(data.mutexes.forks);
	free(data.mutexes.meal_mutex);
	free(data.utils.last_meal_time);
	free(data.utils.meal_eaten);
	pthread_mutex_destroy(&data.mutexes.print_mutex);
	pthread_mutex_destroy(&data.mutexes.stop_mutex);
	write(STDERR_FILENO, "malloc error for philos\n", 28);
	exit(EXIT_FAILURE);
}

void meal_mutex_malloc_error(t_data data)
{
	free(data.mutexes.forks);
	write(STDERR_FILENO, "malloc error for meal_mutex\n", 28);
	exit(EXIT_FAILURE);
}

void philos_threads_malloc_error(t_data data)
{
	long i;

	i = 0;
	while (i < data.args.numbers_of_philos)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	free(data.mutexes.forks);
	free(data.philos);
	free(data.mutexes.meal_mutex);
	free(data.utils.last_meal_time);
	free(data.utils.meal_eaten);
	pthread_mutex_destroy(&data.mutexes.print_mutex);
	pthread_mutex_destroy(&data.mutexes.stop_mutex);
	write(STDERR_FILENO, "malloc error for philos threads\n", 32);
	exit(EXIT_FAILURE);
}