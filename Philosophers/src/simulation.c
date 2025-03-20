/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:52 by nass              #+#    #+#             */
/*   Updated: 2025/03/20 15:33:02 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	lock_and_print(char *to_print, long int current_time, int id, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf(to_print, current_time, id);
	pthread_mutex_unlock(print_mutex);
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
		lock_and_print("%ld %d has taken a fork\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
        if (philo->id != 0)
		    pthread_mutex_lock(philo->right_fork);
        else
            pthread_mutex_lock(philo->left_fork);
		lock_and_print("%ld %d has taken a fork\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);

		lock_and_print("%ld %d is eating\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
		philo->meals_eaten++;
        philo->last_meal_time = get_time_in_ms();
		usleep(philo->time_to_eat * 1000);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
        if (philo->meals_eaten >= philo->meals_to_reach && philo->infinite_loop != true)
            break ;
		lock_and_print("%ld %d is sleeping\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
		usleep(philo->time_to_sleep * 1000);
        lock_and_print("%ld %d is thinking\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
    }
    return (NULL);
}

void launch_simulation(t_utils utils, t_threads *threads_ptr)
{
    int id;

    id = 0;
    threads_ptr->philos_threads = malloc(sizeof(pthread_t) * utils.args.numbers_of_philosophers);
    while (id < utils.args.numbers_of_philosophers)
    {
        pthread_create(&threads_ptr->philos_threads[id], NULL, philo_routine, &utils.philos[id]);
        id++;
    }
}
