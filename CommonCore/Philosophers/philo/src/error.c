/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:28:23 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 12:47:28 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	error_args_case(int error_step)
{
	if (error_step == 1)
		printf("invalid number of arguments\n");
	else if (error_step == 2)
		printf("nb of philos is > MAX_PHILOS or <= 0 or non numeric\n");
	else if (error_step == 3)
		printf("time to die is > LONG_MAX or < 0 or non numeric\n");
	else if (error_step == 4)
		printf("time to eat is > LONG_MAX or < 0 or non numeric\n");
	else if (error_step == 5)
		printf("time to sleep is > LONG_MAX or < 0 or non numeric\n");
	else if (error_step == 6)
		printf("meals to reach is > LONG_MAX or < 0 or non numeric\n");
	return (true);
}
