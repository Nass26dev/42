/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:55:50 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 15:20:36 by nyousfi          ###   ########.fr       */
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

bool	check_args(int argc, char **argv, t_table *table)
{
	if (argc != 5 && argc != 6)
		return (error_args_case(1));
	if (ft_atoll(argv[1]) > MAX_PHILOS || ft_atoll(argv[1]) <= 0)
		return (error_args_case(2));
	table->nb_philos = ft_atoll(argv[1]);
	if (ft_atoll(argv[2]) > LONG_MAX || ft_atoll(argv[2]) <= 0)
		return (error_args_case(3));
	if (ft_atoll(argv[3]) > LONG_MAX || ft_atoll(argv[3]) <= 0)
		return (error_args_case(4));
	if (ft_atoll(argv[4]) > LONG_MAX || ft_atoll(argv[4]) <= 0)
		return (error_args_case(5));
	if (argc == 6)
	{
		if (ft_atoll(argv[5]) > LONG_MAX || ft_atoll(argv[5]) <= 0)
			return (error_args_case(6));
	}
	return (false);
}

bool	create_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (error_forks_case(table, i));
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (error_print_mutex_case(table, table->nb_philos));
	if (pthread_mutex_init(&table->meal_mutex, NULL))
		return (error_meal_mutex_case(table, table->nb_philos));
	return (false);
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
		table->philos[i].last_meal = table->philos[i].start_time;
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
