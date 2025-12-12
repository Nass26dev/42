/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:56:43 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:37:32 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	assign_times(t_data *data)
{
	int		i;
	long	st_time;

	st_time = get_current_time_ms();
	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i].start_time = st_time;
		data->philo[i].last_meal = data->philo[i].start_time;
		i++;
	}
}
