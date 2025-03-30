/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:59:00 by nass              #+#    #+#             */
/*   Updated: 2025/03/30 05:11:45 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        eating_routine(philo);
        lock_and_print("is sleeping", (get_time_in_ms() - philo->start_time), philo->id, &philo->print_mutex);
        usleep(philo->time_to_sleep * 1000);
        lock_and_print("is thinking", (get_time_in_ms() - philo->start_time), philo->id, &philo->print_mutex);
    }
    return (NULL);
}
