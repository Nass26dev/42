/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:29:56 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 08:44:30 by nyousfi          ###   ########.fr       */
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

long verif_arg(char *arg)
{
	long long temp;

	temp = ft_atoll(arg);
	if (temp > LONG_MAX)
	{
		write(STDERR_FILENO, "arg is > than long max\n", 24);
		exit(EXIT_FAILURE);
	}
	return ((long)temp);
}

void recup_args(int argc, char **argv, t_args *args)
{
	if (argc != 5 && argc != 6)
	{
		write(STDERR_FILENO, "invalid numbers of arguments\n", 29);
		exit(EXIT_FAILURE);
	}
	args->numbers_of_philos = verif_arg(argv[1]);
	args->time_to_die = verif_arg(argv[2]);
	args->time_to_eat = verif_arg(argv[3]);
	args->time_to_sleep = verif_arg(argv[4]);
	if (argc == 6)
		args->meals_to_reach = verif_arg(argv[5]);
	else
		args->numbers_of_philos = -1;
}
