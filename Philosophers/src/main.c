/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:20:54 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 10:23:24 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_data d;
	
	check_args(argc, argv);
	create_data(&d, argc, argv);
	create_mutex(&d);
	d.start_time = get_time_ms();
	create_philo_and_monitor(&d);
	launch_simulation(&d);
	wait_and_stop_simulation(&d);
	return (EXIT_SUCCESS);
}
