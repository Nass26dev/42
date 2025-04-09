/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:21:24 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:19:06 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_data data;
	
	recup_args(argc, argv, &data.args);
	create_mutexes(&data);
	create_philos_and_monitor(&data);
	launch_routine(&data);
	// free ressources
	return (0);
}
