/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:19 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 17:47:35 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void check_args(int argc, char **argv)
{
	long long temp;
	
	if (argc != 5 && argc != 6)
		print_and_exit("args format error\n");
	temp = ft_atoll(argv[1]);
	if (temp > LONG_MAX)
 	print_and_exit("numbers_of_philosophers must be < LONG_MAX\n");
	temp = ft_atoll(argv[2]);
	if (temp > LONG_MAX)
		print_and_exit("time_to_die must be < LONG_MAX\n");
	temp = ft_atoll(argv[3]);
	if (temp > LONG_MAX)
		print_and_exit("time_to_eat must be < LONG_MAX\n");
	temp = ft_atoll(argv[4]);
	if (temp > LONG_MAX)
		print_and_exit("time_to_sleep must be < LONG_MAX\n");
	if (argc == 6)
	{
		temp = ft_atoll(argv[5]);
		if (temp > LONG_MAX)
			print_and_exit("meals_to_reach must be < LONG_MAX\n");
	}
}

void create_data(t_data *d_ptr, int argc, char **argv)
{
	d_ptr->a.numbers_of_philos = ft_atoll(argv[1]);
	d_ptr->a.time_to_die = ft_atoll(argv[2]);
	d_ptr->a.time_to_eat = ft_atoll(argv[3]);
	d_ptr->a.time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		d_ptr->a.meals_to_reach = ft_atoll(argv[5]);
	else
		d_ptr->a.meals_to_reach = -1;
	d_ptr->meal_eaten = malloc(sizeof(long) * d_ptr->a.numbers_of_philos);
	d_ptr->last_meal_time = malloc(sizeof(long) * d_ptr->a.numbers_of_philos);
	d_ptr->end_simulation = malloc(sizeof(bool) * d_ptr->a.numbers_of_philos);
}

void create_mutex(t_data *d_ptr)
{
	long id;

	id = 0;
	d_ptr->mu.meal_mutex = malloc(sizeof(pthread_mutex_t) * d_ptr->a.numbers_of_philos);
	d_ptr->mu.forks = malloc(sizeof(pthread_mutex_t) * d_ptr->a.numbers_of_philos);
	while (id < d_ptr->a.numbers_of_philos)
	{
		pthread_mutex_init(&d_ptr->mu.forks[id], NULL);
		pthread_mutex_init(&d_ptr->mu.meal_mutex[id], NULL);
		id++;
	}
	pthread_mutex_init(&d_ptr->mu.print_mutex, NULL);
	pthread_mutex_init(&d_ptr->mu.stop_mutex, NULL);
}

void create_philo_and_monitor(t_data *d_ptr)
{
	long id;

	id = 0;
	d_ptr->p = malloc(sizeof(t_philo) * d_ptr->a.numbers_of_philos);
	*(d_ptr->end_simulation) = false;
	while (id < d_ptr->a.numbers_of_philos)
	{
		init_philo(&d_ptr->p[id], *d_ptr);
		id++;
	}
	d_ptr->mo.end_simulation = d_ptr->end_simulation;
	d_ptr->mo.last_meal_time = d_ptr->last_meal_time;
	d_ptr->mo.meal_eaten = d_ptr->meal_eaten;
	d_ptr->mo.meal_mutex = d_ptr->mu.meal_mutex;
	d_ptr->mo.meals_to_reach = d_ptr->a.meals_to_reach;
	d_ptr->mo.print_mutex = d_ptr->mu.print_mutex;
	d_ptr->mo.start_time = d_ptr->start_time;
	d_ptr->mo.stop_mutex = d_ptr->mu.stop_mutex;
	d_ptr->mo.time_to_die = d_ptr->a.time_to_die;
	d_ptr->mo.nb_philos = d_ptr->a.numbers_of_philos;
}
