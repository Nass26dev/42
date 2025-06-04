/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:53:09 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 14:42:25 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_args(argc, argv, &table))
		return (1);
		// call getimeofday
	if (create_mutexes(&table))
		return (1);
	create_philos(&table, argc, argv);
	if (launch_routine(&table))
		return (1);
	free_ressources(&table);
	return (0);
}
