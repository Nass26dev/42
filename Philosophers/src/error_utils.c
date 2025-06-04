/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:57:45 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 12:21:27 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	error_monitor_case(t_table *table, int nb_philos)
{
	int	i;

	i = 0;
	printf("error during the monitor's thread creation\n");
	while (i < nb_philos)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->meal_mutex);
	return (true);
}

bool	error_philo_case(t_table *table, int nb, t_threads *threads, int nb_thr)
{
	int	i;

	i = 0;
	printf("error during a creation of philo's thread\n");
	while (i < nb)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->meal_mutex);
	pthread_detach(threads->monitor);
	i = 0;
	while (i < nb_thr)
		pthread_detach(threads->philos[i++]);
	return (true);
}
