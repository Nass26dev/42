/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:08:09 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 11:30:46 by nyousfi          ###   ########.fr       */
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

void check_args(int argc, char **argv, t_table *table)
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
