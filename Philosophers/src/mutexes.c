/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:54:50 by nass              #+#    #+#             */
/*   Updated: 2025/03/20 15:31:56 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_mutexes(t_mutexes *mutexes_ptr, t_utils utils)
{
    int id;

    id = 0;
    mutexes_ptr->forks = malloc(sizeof(pthread_mutex_t) * utils.args.numbers_of_philosophers);
    mutexes_ptr->print_mutex = malloc(sizeof(pthread_mutex_t));
    while (id < utils.args.numbers_of_philosophers)
    {
        pthread_mutex_init(&mutexes_ptr->forks[id], NULL);
        id++;
    }
    pthread_mutex_init(mutexes_ptr->print_mutex, NULL);
}
