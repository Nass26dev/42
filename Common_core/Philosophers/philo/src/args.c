/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:26:26 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 12:47:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if ((*str < '0' || *str > '9') && *str != 0)
		return (-1);
	return (nb * sign);
}

bool	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (error_args_case(1));
	if (ft_atoll(argv[1]) > MAX_PHILOS || ft_atoll(argv[1]) <= 0)
		return (error_args_case(2));
	data->nb_philos = ft_atoll(argv[1]);
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
