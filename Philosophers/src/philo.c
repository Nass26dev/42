/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:57:47 by nass              #+#    #+#             */
/*   Updated: 2025/03/20 15:32:03 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init_philo(t_philo *philo_ptr, t_mutexes *mutexes_ptr, t_utils utils, int id)
{
    philo_ptr->id = id;
    philo_ptr->meals_eaten = 0;
    philo_ptr->meals_to_reach = utils.args.meals_to_reach;
    philo_ptr->time_to_die = utils.args.time_to_die;
    philo_ptr->time_to_sleep = utils.args.time_to_sleep;
    philo_ptr->time_to_eat = utils.args.time_to_eat;
    philo_ptr->print_mutex = mutexes_ptr->print_mutex;
    philo_ptr->left_fork = &mutexes_ptr->forks[id];
    philo_ptr->right_fork = &mutexes_ptr->forks[(id + 1) % utils.args.numbers_of_philosophers];
}

void create_philos(t_mutexes mutexes, t_utils *utils_ptr)
{
    int id;

    id = 0;
    utils_ptr->philos = malloc(sizeof(t_philo) * utils_ptr->args.numbers_of_philosophers);
    while (id < utils_ptr->args.numbers_of_philosophers)
    {
        init_philo(&utils_ptr->philos[id], &mutexes, *utils_ptr, id);
        id++;
    }
}
