/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:02:05 by nass              #+#    #+#             */
/*   Updated: 2025/03/20 15:13:16 by nass             ###   ########.fr       */
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
	recup_args(&utils, argv);
	create_mutexes(&mutexes, utils);
	create_philos(mutexes, &utils);
	get_start_time(&utils);
	launch_simulation(utils, &threads);
	wait_threads(utils, threads);
	return (EXIT_SUCCESS);
}
