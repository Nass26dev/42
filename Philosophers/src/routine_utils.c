/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:55:38 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 15:06:54 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_step(t_philo *philo, char *color, char *step)
{
	pthread_mutex_lock(philo->meal_mutex);
	if (philo->meal_reach == 0)
	{
		pthread_mutex_unlock(philo->meal_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->meal_mutex);
	pthread_mutex_lock(philo->print_mutex);
	printf("%s%ld%s", PURPLE, get_current_time_ms() - philo->start_time, RESET);
	printf(" %d", philo->id);
	printf(" %s%s%s\n", color, step, RESET);
	pthread_mutex_unlock(philo->print_mutex);
}

void	usleep_loop(long time_to_sleep)
{
	long	start_time;

	start_time = get_current_time_ms();
	while (get_current_time_ms() - start_time < time_to_sleep)
		usleep(10);
}

void	stop_routine(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo[i].meal_mutex);
	while (i < philo[0].nb_philos)
	{
		philo[i].meal_reach = 0;
		i++;
	}
	pthread_mutex_unlock(philo[i].meal_mutex);
	// pthread_mutex_unlock(&table->print_mutex);
	// i = 0;
	// while (i < table->nb_philos)
	// {
	// 	pthread_join(threads->philos[i], NULL);
	// 	i++;
	// }
}

bool	check_routine_stop(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_mutex);
	if (philo->meal_reach == 0)
	{
		pthread_mutex_unlock(philo->meal_mutex);
		return (true);
	}
	pthread_mutex_unlock(philo->meal_mutex);
	return (false);
}

bool	check_if_is_one(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_mutex);
	if (philo->nb_philos == 1)
	{
		pthread_mutex_unlock(philo->meal_mutex);
		return (true);
	}
	pthread_mutex_unlock(philo->meal_mutex);
	return (false);
}
