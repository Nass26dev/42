/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:02:05 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 08:07:33 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void wait_threads(t_utils utils, t_threads threads)
{
	int id;

	id = 0;
	while (id < utils.args.numbers_of_philosophers)
	{
		pthread_join(threads.philos_threads[id], NULL);
		id++;
	}
	pthread_join(threads.monitor_thread, NULL);
}

int main(int argc, char **argv)
{
	t_mutexes mutexes;
	t_utils utils;
	t_threads threads;

	if (argc != 5 && argc != 6)
    {
        printf(FORMAT);
        return (EXIT_FAILURE);
    }
	create_utils(&utils, argv);
	create_mutexes(&mutexes, utils);
	create_philos(mutexes, &utils);
	create_monitor(mutexes, &utils);
	get_start_time(&utils);
	launch_simulation(utils, &threads);
	wait_threads(utils, threads);
	return (EXIT_SUCCESS);
}
