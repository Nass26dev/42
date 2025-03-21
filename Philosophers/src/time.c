/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:04:39 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 07:57:31 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_time_in_ms(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void get_start_time(t_utils *utils_ptr)
{
	long start_time;
	int id;

	id = 0;
	start_time = get_time_in_ms();
	while (id < utils_ptr->args.numbers_of_philosophers)
	{
		utils_ptr->philos[id].start_time = start_time;
		id++;
	}
	utils_ptr->monitor.start_time = start_time;
}
