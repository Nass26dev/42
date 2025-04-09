/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:51:08 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 13:06:46 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_table table;

	check_args(argc, argv, &table);
	create_mutexes(&table);
	create_philos(&table, argc, argv);
	launch_routines(&table);
	free_ressources(table, table.nb_philos, EXIT_SUCCESS, 3);
	return (0);	
}
