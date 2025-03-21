/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:54:50 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 09:01:56 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_mutexes(t_mutexes *mutexes_ptr, t_utils utils)
{
    int id;

    id = 0;
    mutexes_ptr->forks = malloc(sizeof(pthread_mutex_t) * utils.args.numbers_of_philosophers);
    mutexes_ptr->print_mutex = malloc(sizeof(pthread_mutex_t));
    mutexes_ptr->start_mutexes = malloc(sizeof(pthread_mutex_t) * utils.args.numbers_of_philosophers);
    mutexes_ptr->meals_eaten_mutexes = malloc(sizeof(pthread_mutex_t) * utils.args.numbers_of_philosophers);
    mutexes_ptr->last_meal_time_mutexes = malloc(sizeof(pthread_mutex_t) * utils.args.numbers_of_philosophers);
    mutexes_ptr->end_simulation_mutex = malloc(sizeof(pthread_mutex_t) * utils.args.numbers_of_philosophers);
    while (id < utils.args.numbers_of_philosophers)
    {
        pthread_mutex_init(&mutexes_ptr->forks[id], NULL);
        pthread_mutex_init(&mutexes_ptr->start_mutexes[id], NULL);
        pthread_mutex_init(&mutexes_ptr->last_meal_time_mutexes[id], NULL);
        pthread_mutex_init(&mutexes_ptr->meals_eaten_mutexes[id], NULL);
        id++;
    }
    pthread_mutex_init(mutexes_ptr->end_simulation_mutex, NULL);
    pthread_mutex_init(mutexes_ptr->print_mutex, NULL);
}
