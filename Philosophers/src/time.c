/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:55:40 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:17:34 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_time_in_ms()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void add_start_time(t_data *data)
{
	long id;
	long start_time;
	
	id = 0;
	start_time = get_time_in_ms();
	while (id < data->args.numbers_of_philos)
	{
		data->philos->start_time = start_time;
		id++;
	}
	data->monitor.start_time = start_time;
}
