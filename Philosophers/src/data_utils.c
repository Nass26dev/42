/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:33:11 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 17:47:42 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_and_exit(char *to_print)
{
	printf("%s", to_print);
	exit(EXIT_FAILURE);
}

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

long get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void init_philo(t_philo *new_philo, t_data data)
{
	static long id;

	new_philo->id = id;
	new_philo->meals_to_reach = data.a.meals_to_reach;
	new_philo->meal_eaten = &data.meal_eaten[id];
	*(new_philo->meal_eaten) = 0;
	new_philo->last_meal_time = &data.last_meal_time[id];
	new_philo->left_fork = &data.mu.forks[id];
    new_philo->right_fork = &data.mu.forks[(id + 1) % data.a.numbers_of_philos];
	new_philo->print_mutex = data.mu.print_mutex;
	new_philo->meal_mutex = &data.mu.meal_mutex[id];
	new_philo->start_time = data.start_time;
	new_philo->stop_mutex = data.mu.stop_mutex;
	new_philo->stop_simulation = data.end_simulation;
	new_philo->time_to_eat = data.a.time_to_eat;
	new_philo->time_to_sleep = data.a.time_to_sleep;
	id++;
}
