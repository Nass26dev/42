/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:40:57 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 17:50:04 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void lock_and_print_philo(char *to_print, t_philo *philo)
{
	pthread_mutex_lock(&philo->print_mutex);
	pthread_mutex_lock(&philo->stop_mutex);
	if (*(philo->stop_simulation))
	{
		pthread_mutex_unlock(&philo->stop_mutex);
		pthread_mutex_unlock(&philo->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->stop_mutex);
	printf("%ld %ld %s\n", (get_time_ms() - philo->start_time), philo->id, to_print);
	pthread_mutex_unlock(&philo->print_mutex);
}

bool check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop_mutex);
	if (*(philo->stop_simulation))
	{
		pthread_mutex_unlock(&philo->stop_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->stop_mutex);
	return (false);
}

void eating_routine(t_philo *philo)
{
	if (philo->id != 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	lock_and_print_philo("has taken a fork", philo);
	if (philo->id != 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	lock_and_print_philo("has taken a fork", philo);
	lock_and_print_philo("is eating", philo);
	pthread_mutex_lock(philo->meal_mutex);
	if (*philo->meal_eaten <= philo->meals_to_reach)
		*(philo->meal_eaten) = *(philo->meal_eaten) + 1;
	*(philo->last_meal_time) = get_time_ms();
	pthread_mutex_unlock(philo->meal_mutex);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

bool check_meals(t_monitor *monitor)
{
	long id;

	id = 0;
	while (id < monitor->nb_philos)
	{
		pthread_mutex_lock(&monitor->meal_mutex[id]);
		if (monitor->meal_eaten[id] < monitor->meals_to_reach)
		{
			pthread_mutex_unlock(&monitor->meal_mutex[id]);
			return (false);
		}
		pthread_mutex_unlock(&monitor->meal_mutex[id]);
		id++;
	}
	id = 0;
	pthread_mutex_lock(&monitor->stop_mutex);
	*(monitor->end_simulation) = true;
	pthread_mutex_unlock(&monitor->stop_mutex);
	pthread_mutex_lock(&monitor->print_mutex);
	pthread_mutex_unlock(&monitor->print_mutex);
	return (true);
}
