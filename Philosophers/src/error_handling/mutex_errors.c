/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:56:09 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 09:54:30 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void forks_init_error(long nb, t_data data)
{
	long i;
	
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		if (i != nb - 1)
			pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	free(data.mutexes.forks);
	free(data.mutexes.meal_mutex);
	write(STDERR_FILENO, "error during the initialisation of forks\n", 41);
	exit(EXIT_FAILURE);
}

void print_mutex_init_error(t_data data)
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
	write(STDERR_FILENO, "error during the initialisation of print_mutex\n", 47);
	exit(EXIT_FAILURE);
}

void stop_mutex_init_error(t_data data)
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
	write(STDERR_FILENO, "error during the initialisation of stop_mutex\n", 46);
	exit(EXIT_FAILURE);
}

void meal_mutex_init_error(long nb, t_data data)
{
	long i;
	
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	free(data.mutexes.forks);
	free(data.mutexes.meal_mutex);
	write(STDERR_FILENO, "error during the initialisation of meal_mutex\n", 46);
	exit(EXIT_FAILURE);
}
