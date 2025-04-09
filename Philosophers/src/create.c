/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:21:11 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 12:37:59 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_mutexes(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			free_ressources(*table, i, EXIT_FAILURE, 1);
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL))
	{
		write(STDERR_FILENO, "mutex init error for print_mutex\n", 33);
		free_ressources(*table, table->nb_philos, EXIT_FAILURE, 2);
	}
	if (pthread_mutex_init(&table->meal_mutex, NULL))
	{
		write(STDERR_FILENO, "mutex init error for meal_mutex\n", 32);
		free_ressources(*table, table->nb_philos, EXIT_FAILURE, 3);
	}
}

void create_philos(t_table *table, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].t_die = ft_atoll(argv[2]);
		table->philos[i].t_eat = ft_atoll(argv[3]);
		table->philos[i].t_sleep = ft_atoll(argv[4]);
		table->philos[i].start_time = get_current_time_ms();
		table->philos[i].last_meal = get_current_time_ms();
		if (argc == 6)
			table->philos[i].meal_reach = ft_atoll(argv[5]);
		else
			table->philos[i].meal_reach = -1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].nb_philos = table->nb_philos;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->nb_philos];
		table->philos[i].print_mutex = &table->print_mutex;
		table->philos[i].meal_mutex = &table->meal_mutex;
		i++;
	}
	
}
