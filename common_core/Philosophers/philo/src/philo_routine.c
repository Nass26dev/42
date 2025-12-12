/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:27:38 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 11:56:50 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_mutex);
	if (philo->nb_philos == 1)
	{
		pthread_mutex_unlock(philo->philo_mutex);
		print_step(philo, YELLOW, "has taken a fork");
		return (true);
	}
	pthread_mutex_unlock(philo->philo_mutex);
	return (false);
}

bool	check_routine_stop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (*(philo->is_dead))
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return (true);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (false);
}

void	try_to_take_left_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		if (!*(philo->l_fork))
		{
			*(philo->l_fork) = true;
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		pthread_mutex_unlock(philo->left_fork);
		usleep(200);
	}
}

void	try_to_take_right_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->right_fork);
		if (!*(philo->r_fork))
		{
			*(philo->r_fork) = true;
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		pthread_mutex_unlock(philo->right_fork);
		usleep(200);
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		*(philo->l_fork) = false;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		*(philo->r_fork) = false;
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		*(philo->r_fork) = false;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		*(philo->l_fork) = false;
		pthread_mutex_unlock(philo->left_fork);
	}
}
