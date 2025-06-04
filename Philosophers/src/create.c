/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:21:11 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 09:56:27 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_atoll(const char *str)
{
	long long	nb;
	int			sign;

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
	if (*str < '0' || *str > '9')
		return (LLONG_MAX);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (*str < '0' && *str > '9' && *str != 0)
		return (LLONG_MAX);
	return (nb * sign);
}

void	check_args(int argc, char **argv, t_table *table)
{
	if (argc != 5 && argc != 6)
		print_error("invalid number of arguments\n", 28);
	if (ft_atoll(argv[1]) > MAX_PHILOS)
		print_error("nb of philos is > MAX_PHILOS\n", 27);
	table->nb_philos = ft_atoll(argv[1]);
	if (ft_atoll(argv[2]) > LONG_MAX)
		print_error("time to die is > LONG_MAX\n", 26);
	if (ft_atoll(argv[3]) > LONG_MAX)
		print_error("time to eat is > LONG_MAX\n", 26);
	if (ft_atoll(argv[4]) > LONG_MAX)
		print_error("time to sleep is > LONG_MAX\n", 28);
	if (argc == 6)
	{
		if (ft_atoll(argv[5]) > LONG_MAX)
			print_error("meals to reach is > LONG_MAX\n", 29);
	}
}

void	create_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			free_ressources(*table, i, EXIT_FAILURE, 1);
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL))
	{
		write(STDERR_FILENO, "mutex init error for print_mutex\n", 33);
		free_ressources(*table, table->nb_philos, EXIT_FAILURE, 2);
	}
	if (pthread_mutex_init(&table->meal_mutex, NULL))
	{
		write(STDERR_FILENO, "mutex init error for meal_mutex\n", 32);
		free_ressources(*table, table->nb_philos, EXIT_FAILURE, 3);
	}
}

void	create_philos(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].t_die = ft_atoll(argv[2]);
		table->philos[i].t_eat = ft_atoll(argv[3]);
		table->philos[i].t_sleep = ft_atoll(argv[4]);
		table->philos[i].start_time = get_current_time_ms();
		table->philos[i].last_meal = get_current_time_ms();
		if (argc == 6)
			table->philos[i].meal_reach = ft_atoll(argv[5]);
		else
			table->philos[i].meal_reach = -1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].nb_philos = table->nb_philos;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->nb_philos];
		table->philos[i].print_mutex = &table->print_mutex;
		table->philos[i].meal_mutex = &table->meal_mutex;
		i++;
	}
}
