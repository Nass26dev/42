/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:27:14 by nyousfi           #+#    #+#             */
/*   Updated: 2025/03/17 16:27:34 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_death(t_monitor *monitor)
{
	t_meal_node *current;

	current = monitor->meal_lst;
	while (current)
	{
		if ((monitor->time - *(current->last_meal)) >= monitor->time_to_die)
		{
			lock_and_print("%ld %d is dead\n", monitor->time, current->id, monitor->print_mutex);
			*(monitor->stop) = 1;
			break ;
		}
		current = current->next;
	}
}

void *monitor_routine(void *arg)
{
	t_monitor *monitor;
	
	monitor = (t_monitor *)arg;
	while (1)
	{
		monitor->time = get_time_in_ms(monitor->start_time);
		check_death(monitor);
		if (*(monitor->stop))
			break ;
	}
	return (NULL);
}

void add_node(t_philo *philos, int id, t_meal_node *start)
{
	t_meal_node *new;
	t_meal_node *current;

	new = malloc(sizeof(t_meal_node));
	new->id = id;
	new->last_meal = philos[id].last_meal_time;
	new->next = NULL;
	current = start;
	if (start)
		start = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_meal_node *init_lst(t_philo *philos, t_args args)
{
	int i;
	t_meal_node *lst;
	
	lst = NULL;
	i = 0;
	while (i < args.numbers_of_philosophers)
	{
		add_node(philos, i, lst);
		i++;
	}
	return (lst);
}

pthread_t create_monitor(t_args args, t_philo *philos, pthread_mutex_t *print_mutex, struct timeval start_time)
{
	t_monitor monitor;
	pthread_t monitor_thread;

	monitor.meal_lst = init_lst(philos, args);
	monitor.nb_philos = args.numbers_of_philosophers;
	monitor.print_mutex = print_mutex;
	monitor.start_time = start_time;
	*(monitor.stop) = 0;
	monitor.time_to_die = args.time_to_die;
	pthread_create(&monitor_thread, NULL, monitor_routine, &monitor);
	return (monitor_thread);
}
