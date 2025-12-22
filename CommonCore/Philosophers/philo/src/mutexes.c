/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:29:43 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:37:13 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (error_forks_case(data, i));
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (error_forks_case(data, data->nb_philos));
	if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
		return (error_dead_case(data));
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (error_meal_case(data));
	if (pthread_mutex_init(&data->time_mutex, NULL) != 0)
		return (error_time_case(data));
	if (pthread_mutex_init(&data->philo_mutex, NULL) != 0)
		return (error_philo_mutex_case(data));
	return (false);
}
