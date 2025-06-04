/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:10:24 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 12:42:22 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	error_args_case(int error_step)
{
	if (error_step == 1)
		printf("invalid number of arguments\n");
	else if (error_step == 2)
		printf("nb of philos is > MAX_PHILOS or < 0\n");
	else if (error_step == 3)
		printf("time to die is > LONG_MAX or < 0\n");
	else if (error_step == 4)
		printf("time to eat is > LONG_MAX or < 0\n");
	else if (error_step == 5)
		printf("time to sleep is > LONG_MAX or < 0\n");
	else if (error_step == 6)
		printf("meals to reach is > LONG_MAX or < 0\n");
	return (true);
}

bool	error_forks_case(t_table *table, int nb_forks)
{
	int	i;

	i = 0;
	printf("Error during a fork_mutex creation\n");
	while (i < nb_forks)
		pthread_mutex_destroy(&table->forks[i++]);
	return (true);
}

bool	error_print_mutex_case(t_table *table, int nb_forks)
{
	int	i;

	i = 0;
	printf("Error during print_mutex creation\n");
	while (i < nb_forks)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_mutex);
	return (true);
}

bool	error_meal_mutex_case(t_table *table, int nb_forks)
{
	int	i;

	i = 0;
	printf("Error during meal_mutex creation\n");
	while (i < nb_forks)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->meal_mutex);
	return (true);
}
