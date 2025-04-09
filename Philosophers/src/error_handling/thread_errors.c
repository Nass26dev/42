/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:05:02 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:17:52 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void monitor_thread_error(t_data data)
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
	free(data.threads.philos_threads);
	pthread_mutex_destroy(&data.mutexes.print_mutex);
	pthread_mutex_destroy(&data.mutexes.stop_mutex);
	write(STDERR_FILENO, "Error during the creation of monitor thread\n", 44);
	exit(EXIT_FAILURE);
}

void stop_threads(long nb, t_data data)
{
	long i;

	i = 0;
	if (nb != 0)
	{
		pthread_mutex_lock(data.philos[i].stop_mutex);
		*(data.philos[i].stop_simulation) = true;
		pthread_mutex_unlock(data.philos[i].stop_mutex);
	}
	else
		return ;
	while (i < nb)
	{
		pthread_join(data.threads.philos_threads[i], NULL);
		i++;
	}
}

void philo_thread_error(long nb, t_data data)
{
	long i;

	i = 0;
	while (i < data.args.numbers_of_philos)
	{
		pthread_mutex_destroy(&data.mutexes.forks[i]);
		pthread_mutex_destroy(&data.mutexes.meal_mutex[i]);
		i++;
	}
	stop_threads(nb, data);
	free(data.mutexes.forks);
	free(data.philos);
	free(data.mutexes.meal_mutex);
	free(data.utils.last_meal_time);
	free(data.utils.meal_eaten);
	free(data.threads.philos_threads);
	pthread_mutex_destroy(&data.mutexes.print_mutex);
	pthread_mutex_destroy(&data.mutexes.stop_mutex);
	write(STDERR_FILENO, "Error during the creation of philo thread\n", 42);
	exit(EXIT_FAILURE);
}
