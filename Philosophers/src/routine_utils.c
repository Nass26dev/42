/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 05:03:37 by nass              #+#    #+#             */
/*   Updated: 2025/03/30 05:10:52 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	lock_and_print(char *to_print, long current_time, int id, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf("%ld %d %s\n", current_time, id, to_print);
	pthread_mutex_unlock(print_mutex);
}

void eating_routine(t_philo *philo)
{
    if (philo->id != 0)
        pthread_mutex_lock(philo->left_fork);
    else
        pthread_mutex_lock(philo->right_fork);
    lock_and_print("has taken a fork", (get_time_in_ms() - philo->start_time), philo->id, &philo->print_mutex);
    if (philo->id != 0)
        pthread_mutex_lock(philo->right_fork);
    else
        pthread_mutex_lock(philo->left_fork);
    lock_and_print("has taken a fork", (get_time_in_ms() - philo->start_time), philo->id, &philo->print_mutex);
    lock_and_print("is eating", (get_time_in_ms() - philo->start_time), philo->id, &philo->print_mutex);
    philo->meal_eaten++;
    philo->last_meal_time = get_time_in_ms();
    usleep(philo->time_to_eat * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
