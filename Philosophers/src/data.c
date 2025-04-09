/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:12:01 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 09:19:01 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void fill_data_with_utils(t_data *data)
{
	bool stop_simulation;

	data->utils.stop_simulation = &stop_simulation;
	data->utils.last_meal_time = malloc(sizeof(long) * data->args.numbers_of_philos);
	if (!data->utils.last_meal_time)
		last_meal_time_malloc_error(*data);
	data->utils.meal_eaten = malloc(sizeof(long) * data->args.numbers_of_philos);
	if (!data->utils.meal_eaten)
		meal_eaten_malloc_error(*data);
}
