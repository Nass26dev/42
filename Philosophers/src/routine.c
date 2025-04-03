/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:40:27 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 13:28:29 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *monitor_routine(void *arg)
{
	t_monitor *monitor;

	monitor = (t_monitor *)arg;
	while (1)
	{
		usleep(100);
		if (check_meals(monitor))
			break ;
		// check_death();
	}
	return (NULL);
}

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_stop(philo))
			break ;
		eating_routine(philo);
		lock_and_print_philo("is sleeping", philo);
		usleep(philo->time_to_sleep * 1000);
		lock_and_print_philo("is thinking", philo);
	}
	return (NULL);
}

void launch_simulation(t_data *d_ptr)
{
	long id;
	
	id = 0;
	d_ptr->t.philo_t = malloc(sizeof(pthread_t) * d_ptr->a.numbers_of_philos);
	pthread_create(&d_ptr->t.monitor_t, NULL, monitor_routine, (void *)&d_ptr->mo);
	while (id < d_ptr->a.numbers_of_philos)
	{
		pthread_mutex_lock(&d_ptr->mu.print_mutex);
		pthread_mutex_unlock(&d_ptr->mu.print_mutex);
		pthread_create(&d_ptr->t.philo_t[id], NULL, philo_routine, (void *)&d_ptr->p[id]);
		id++;
	}
	
}

void wait_and_stop_simulation(t_data *d_ptr)
{
	long id;

	id = 0;
	while (id < d_ptr->a.numbers_of_philos)
	{
		pthread_join(d_ptr->t.philo_t[id], NULL);
		id++;
	}
	pthread_join(d_ptr->t.monitor_t, NULL);
}
