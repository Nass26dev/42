/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:54:14 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:33:43 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *monitor_routine(void *arg)
{
	(void)arg;
	return (NULL);
}

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->id != 0)
			pthread_mutex_lock(philo->left_fork);
		else
			pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld, %ld has taken a fork\n", get_time_in_ms() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
		if (philo->id != 0)
			pthread_mutex_lock(philo->right_fork);
		else
			pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld, %ld has taken a fork\n", get_time_in_ms() - philo->start_time, philo->id);
		printf("%ld, %ld is eating\n", get_time_in_ms() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld, %ld is sleeping\n", get_time_in_ms() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
		usleep(philo->time_to_sleep * 1000);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld, %ld is thinking\n", get_time_in_ms() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
	}
	return (NULL);	
}

void launch_routine(t_data *data)
{
	long i;

	i = 0;
	add_start_time(data);
	data->threads.philos_threads = malloc(sizeof(pthread_t) * data->args.numbers_of_philos);
	if (!data->threads.philos_threads)
		philos_threads_malloc_error(*data);
	if (pthread_create(&data->threads.monitor_thread, NULL, monitor_routine, (void *)&data->monitor))
		monitor_thread_error(*data);
	while (i < data->args.numbers_of_philos)
	{
		if (pthread_create(&data->threads.philos_threads[i], NULL, philo_routine, &data->philos[i]))
			philo_thread_error(i, *data);
		i++;
	}
	i = 0;
	pthread_join(data->threads.monitor_thread, NULL);
	while (i < data->args.numbers_of_philos)
	{
		pthread_join(data->threads.philos_threads[i], NULL);
		i++;
	}
}
