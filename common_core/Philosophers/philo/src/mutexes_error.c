/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:32:24 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/03 17:40:53 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	error_forks_case(t_data *data, int nb_forks)
{
	int	i;

	i = 0;
	printf("Error during a fork_mutex creation\n");
	while (i < nb_forks)
		pthread_mutex_destroy(&data->forks[i++]);
	return (true);
}

bool	error_philo_mutex_case(t_data *data)
{
	int	i;

	i = 0;
	printf("Error during philo thread creation\n");
	while (i < data->nb_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->time_mutex);
	return (true);
}

bool	error_dead_case(t_data *data)
{
	int	i;

	i = 0;
	printf("Error during dead_mutex creation\n");
	while (i < data->nb_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	return (true);
}

bool	error_meal_case(t_data *data)
{
	int	i;

	i = 0;
	printf("Error during meal_mutex creation\n");
	while (i < data->nb_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	return (true);
}

bool	error_time_case(t_data *data)
{
	int	i;

	i = 0;
	printf("Error during time_mutex creation\n");
	while (i < data->nb_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	return (true);
}
