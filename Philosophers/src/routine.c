/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:52:25 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 13:04:59 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool all_meals_reached(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos[0].nb_philos)
	{
		if (philos[i].meals_eaten >= philos[i].meal_reach)
			i++;
		else
			return (false);
	}
	return (true);
}

void *monitor_routine(void *arg)
{
	t_philo *philos;
	int i;

	i = 0;
	philos = (t_philo *)arg;
	while (1)
	{
		usleep(25);
		while (i < philos[0].nb_philos)
		{
			pthread_mutex_lock(philos->meal_mutex);
			if (get_current_time_ms() - philos[i].last_meal > philos[i].t_die)
			{
				pthread_mutex_unlock(philos->meal_mutex);
				
				pthread_mutex_lock(philos[i].print_mutex);
				printf("%ld", get_current_time_ms() - philos[i].start_time);
				printf(" %d %s%s%s\n", philos[i].id, RED, "is dead", RESET);
				return (NULL);
			}
			pthread_mutex_unlock(philos->meal_mutex);
			i++;
		}
		if (all_meals_reached(philos))
			return (NULL);
	}
	return (NULL);
}

void philo_routine(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_step(philo, BLUE, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_step(philo, BLUE, "has taken a fork");
		pthread_mutex_lock(philo->meal_mutex);
		print_step(philo, GREEN, "is eating");
		philo->last_meal = get_current_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->meal_mutex);
		usleep(philo->t_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_step(philo, GREEN, "is sleeping");
		usleep(philo->t_sleep * 1000);
		print_step(philo, GREEN, "is thinking");
	}
}

void *launch_philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->meal_mutex);
	philo->start_time = get_current_time_ms();
	philo->last_meal = get_current_time_ms();
	pthread_mutex_unlock(philo->meal_mutex);
	philo_routine(philo); 
	return (NULL);
}

void launch_routines(t_table *table)
{
	t_threads threads;
	int i;
	
	if (pthread_create(&threads.monitor, NULL, monitor_routine, table->philos))
		free_ressources(*table, table->nb_philos, EXIT_FAILURE, 3);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_create(&threads.philos[i], NULL, launch_philo_routine, &table->philos[i]);
		i++;
	}
	pthread_join(threads.monitor, NULL);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_detach(threads.philos[i]);
		i++;
	}
}
