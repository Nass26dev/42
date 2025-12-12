/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:15:06 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:37:03 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv, &data))
		return (1);
	if (create_mutexes(&data))
		return (1);
	create_philos(&data, argc, argv);
	assign_times(&data);
	if (launch_routines(&data))
		return (1);
	free_ressources(&data);
	return (0);
}
