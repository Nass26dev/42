/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:46:52 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 09:05:06 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_monitor(t_mutexes mutexes, t_utils *utils_ptr)
{
    utils_ptr->monitor.end_simulation_mutex = mutexes.end_simulation_mutex;
    utils_ptr->monitor.end_simulation = utils_ptr->end_simulation;
    utils_ptr->monitor.print_mutex = mutexes.print_mutex;
    utils_ptr->monitor.infinite_loop = utils_ptr->args.infinite_loop;
    utils_ptr->monitor.meals_to_reach = utils_ptr->args.meals_to_reach;
    utils_ptr->monitor.numbers_of_philosophers = utils_ptr->args.numbers_of_philosophers;
    utils_ptr->monitor.start_mutexes = mutexes.start_mutexes;
    utils_ptr->monitor.running_lst = utils_ptr->running_lst;
    utils_ptr->monitor.time_to_die = utils_ptr->args.time_to_die;
    utils_ptr->monitor.meals_eaten_lst = utils_ptr->meals_eaten_lst;
    utils_ptr->monitor.last_meal_time_lst = utils_ptr->last_meals_time;
    utils_ptr->monitor.last_meal_time_mutex = mutexes.last_meal_time_mutexes;
    utils_ptr->monitor.meals_eaten_mutex = mutexes.meals_eaten_mutexes;
}
