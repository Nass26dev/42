/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:37:00 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:36:59 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_ressources(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->time_mutex);
}
