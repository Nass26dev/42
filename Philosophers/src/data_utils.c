/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:45:14 by nass              #+#    #+#             */
/*   Updated: 2025/03/30 05:09:27 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_and_exit(char *error_msg)
{
    printf("%s\n", error_msg);
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
	if (*str < '0' && *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

void init_philo(t_philo *new_philo, t_data data)
{
    static int id;
    
    new_philo->id = id;
    new_philo->meal_eaten = 0;
    new_philo->meals_to_reach = data.args.meals_to_reach;
    new_philo->time_to_die = data.args.time_to_die;
    new_philo->time_to_eat = data.args.time_to_eat;
    new_philo->time_to_sleep = data.args.time_to_sleep;
    new_philo->print_mutex = data.mutexes.print_mutex;
    new_philo->left_fork = &data.mutexes.forks[id];
    new_philo->right_fork = &data.mutexes.forks[(id + 1) % data.args.numbers_of_philosophers];
    new_philo->start_time = data.start_time;
    id++;
}

long get_time_in_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
