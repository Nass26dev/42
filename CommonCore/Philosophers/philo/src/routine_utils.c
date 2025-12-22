/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:35:10 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 14:13:18 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_step(t_philo *philo, char *color, char *step)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(philo->dead_mutex);
	if (*(philo->is_dead))
	{
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(philo->dead_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->dead_mutex);
	printf("%s%ld%s %d %s%s%s\n", PURPLE, get_current_time_ms()
		- philo->start_time, RESET, philo->id, color, step, RESET);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_for_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(philo->dead_mutex);
	if (*(philo->is_dead))
	{
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(philo->dead_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->dead_mutex);
	printf("%s%ld%s %d %s%s%s\n", PURPLE, get_current_time_ms()
		- philo->start_time, RESET, philo->id, YELLOW, "has taken a fork",
		RESET);
	printf("%s%ld%s %d %s%s%s\n", PURPLE, get_current_time_ms()
		- philo->start_time, RESET, philo->id, ORANGE, "has taken a fork",
		RESET);
	pthread_mutex_unlock(philo->print_mutex);
}

void	usleep_loop(long time_to_sleep, t_philo *philo)
{
	long	start_time;

	start_time = get_current_time_ms();
	while (get_current_time_ms() - start_time < time_to_sleep)
	{
		if (check_routine_stop(philo))
			return ;
		usleep(500);
	}
}

void	takes_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		try_to_take_left_fork(philo);
	else
		try_to_take_right_fork(philo);
	print_step(philo, YELLOW, "has taken a fork");
	if (philo->id % 2 == 0)
		try_to_take_right_fork(philo);
	else
		try_to_take_left_fork(philo);
	print_step(philo, ORANGE, "has taken a fork");
}
