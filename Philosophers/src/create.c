/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:49:23 by nass              #+#    #+#             */
/*   Updated: 2025/03/11 08:44:16 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo init_philo(t_args args, pthread_mutex_t *forks, int id, pthread_mutex_t *print_mutex, struct timeval start_time)
{
	t_philo philo;

	philo.print_mutex = print_mutex;
	philo.id = id;
	philo.max_meals = args.max_meals;
	philo.meals_eaten = 0;
	philo.time_to_die = args.time_to_die;
	philo.time_to_eat = args.time_to_eat;
	philo.time_to_sleep = args.time_to_sleep;
	philo.left_fork = &forks[id];
	philo.right_fork = &forks[(id + 1) % args.numbers_of_philosophers];
	philo.start_time = start_time;
	return (philo);
}

t_philo *create_philos(t_args args, pthread_mutex_t *forks, pthread_mutex_t *print_mutex, struct timeval start_time)
{
	t_philo *philos;
	int		id;

	id = 0;
	philos = malloc(args.numbers_of_philosophers * sizeof(t_philo));
	while (id < args.numbers_of_philosophers)
	{
		philos[id] = init_philo(args, forks, id, print_mutex, start_time);
		id++;
	}
	return (philos);
}

pthread_mutex_t *create_forks(t_args args)
{
	int				i;
	pthread_mutex_t *forks;
	
	i = 0;
	forks = malloc(args.numbers_of_philosophers * sizeof(pthread_mutex_t));
	while (i < args.numbers_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

pthread_t *create_threads(t_args args, t_philo *philos)
{
	int id;
	pthread_t *threads;
	
	id = 0;
	threads = malloc(args.numbers_of_philosophers * sizeof(pthread_t));
	while (id < args.numbers_of_philosophers)
	{
		pthread_create(&threads[id], NULL, routine, &philos[id]);
		id++;
	}
	return (threads);
}

long int	ft_atol(const char *str)
{
	long int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -sign;
		str++;
	}
	if (*str < '0' && *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

t_args recup_args(char **argv)
{
	t_args args;

	args.numbers_of_philosophers = ft_atol(argv[1]);
	args.time_to_die = ft_atol(argv[2]);
	args.time_to_eat = ft_atol(argv[3]);
	args.time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		args.max_meals = ft_atol(argv[5]);
	else
		args.max_meals = 100;
	return (args);
}
