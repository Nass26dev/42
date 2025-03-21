/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:52 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 10:23:29 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	lock_and_print(char *to_print, long int current_time, int id, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf(to_print, current_time, id);
	pthread_mutex_unlock(print_mutex);
}

bool check_meals_reached(t_monitor *monitor)
{
    int id;

    id = 0;
    while (id < monitor->numbers_of_philosophers)
    {
        pthread_mutex_lock(&monitor->start_mutexes[id]);
        if (monitor->running_lst[id])
        {
            pthread_mutex_unlock(&monitor->start_mutexes[id]);
            pthread_mutex_lock(&monitor->meals_eaten_mutex[id]);
            if (monitor->meals_eaten_lst[id] >= monitor->meals_to_reach)
            {
                pthread_mutex_unlock(&monitor->meals_eaten_mutex[id]);
                id++;
            }
            else
            {
                pthread_mutex_unlock(&monitor->meals_eaten_mutex[id]);
                return (false);
            }
        }
    }
    if (monitor->infinite_loop)
        return (false);
    return (true);
}

bool check_death(t_monitor *monitor)
{
    int id;

    id = 0;
    while (id < monitor->numbers_of_philosophers)
    {
        pthread_mutex_lock(monitor->start_mutexes);
        if (monitor->running_lst[id])
        {
            pthread_mutex_unlock(monitor->start_mutexes);
            pthread_mutex_lock(monitor->last_meal_time_mutex);
            if (((monitor->current_time - monitor->last_meal_time_lst[id]) - (monitor->time_to_eat + monitor->time_to_sleep)) > monitor->time_to_die)
            {
                lock_and_print("%ld %d is dead\n", monitor->current_time - monitor->start_time, id, monitor->print_mutex);
                pthread_mutex_unlock(monitor->last_meal_time_mutex);
                return (true);
            }
            pthread_mutex_unlock(monitor->last_meal_time_mutex);
        }
        pthread_mutex_unlock(monitor->start_mutexes);
        id++;
    }
    return (false);   
}

void *monitor_routine(void *arg)
{
    t_monitor *monitor;

    monitor = (t_monitor *)arg;
    while (1)
    {
        usleep(25);
        monitor->current_time = get_time_in_ms();
        if (check_meals_reached(monitor))
        {
            pthread_mutex_lock(monitor->end_simulation_mutex);
            *(monitor->end_simulation) = true;
            pthread_mutex_unlock(monitor->end_simulation_mutex);
            break ;
        }
        if (check_death(monitor))
        {
            pthread_mutex_lock(monitor->end_simulation_mutex);
            *(monitor->end_simulation) = true;
            pthread_mutex_unlock(monitor->end_simulation_mutex);
            break ;
        }
    }
    return (NULL);
}

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    pthread_mutex_lock(philo->start_mutex);
    pthread_mutex_lock(philo->last_meal_time_mutex);
    *(philo->last_meal_time) = get_time_in_ms();
    pthread_mutex_unlock(philo->last_meal_time_mutex);
    *(philo->running) = true;
    pthread_mutex_unlock(philo->start_mutex);
    while (!*(philo->end_simulation))
    {
        if (philo->id != 0)
            pthread_mutex_lock(philo->left_fork);
        else
            pthread_mutex_lock(philo->right_fork);
            
        pthread_mutex_lock(philo->end_simulation_mutex);
        if (!*(philo->end_simulation))
		    lock_and_print("%ld %d has taken a fork\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
        pthread_mutex_unlock(philo->end_simulation_mutex);
        
        if (philo->id != 0)
		    pthread_mutex_lock(philo->right_fork);
        else
            pthread_mutex_lock(philo->left_fork);
            
        pthread_mutex_lock(philo->end_simulation_mutex);
        if (!*(philo->end_simulation))
        {
		    lock_and_print("%ld %d has taken a fork\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
            lock_and_print("%ld %d is eating\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
        }
        pthread_mutex_unlock(philo->end_simulation_mutex);
        
        pthread_mutex_lock(philo->meals_eaten_mutex);
		(*(philo->meals_eaten))++;
        pthread_mutex_unlock(philo->meals_eaten_mutex);
        pthread_mutex_lock(philo->last_meal_time_mutex);
        *(philo->last_meal_time) = get_time_in_ms();
        pthread_mutex_unlock(philo->last_meal_time_mutex);
		usleep(philo->time_to_eat * 1000);
        
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_lock(philo->end_simulation_mutex);
        if (!*(philo->end_simulation))
		    lock_and_print("%ld %d is sleeping\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
        pthread_mutex_unlock(philo->end_simulation_mutex);
		usleep(philo->time_to_sleep * 1000);
        pthread_mutex_lock(philo->end_simulation_mutex);
        if (!*(philo->end_simulation))
            lock_and_print("%ld %d is thinking\n", (get_time_in_ms() - philo->start_time), philo->id, philo->print_mutex);
        pthread_mutex_unlock(philo->end_simulation_mutex);
    }
    return (NULL);
}

void launch_simulation(t_utils utils, t_threads *threads_ptr)
{
    int id;

    id = 0;
    threads_ptr->philos_threads = malloc(sizeof(pthread_t) * utils.args.numbers_of_philosophers);
    pthread_create(&threads_ptr->monitor_thread, NULL, monitor_routine, &utils.monitor);
    while (id < utils.args.numbers_of_philosophers)
    {
        pthread_create(&threads_ptr->philos_threads[id], NULL, philo_routine, &utils.philos[id]);
        id++;
    }
}
