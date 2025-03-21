/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:50:28 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 09:05:15 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	ft_atol(const char *str)
{
	long int	nb;
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

void	create_utils(t_utils *utils_ptr, char **argv)
{
	utils_ptr->args.numbers_of_philosophers = ft_atol(argv[1]);
	utils_ptr->args.time_to_die = ft_atol(argv[2]);
	utils_ptr->args.time_to_eat = ft_atol(argv[3]);
	utils_ptr->args.time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
    {
		utils_ptr->args.meals_to_reach = ft_atol(argv[5]);
        utils_ptr->args.infinite_loop = false;
    }
	else
		utils_ptr->args.infinite_loop = true;
	utils_ptr->running_lst = malloc(sizeof(bool) * utils_ptr->args.numbers_of_philosophers);
	utils_ptr->meals_eaten_lst = malloc(sizeof(int) * utils_ptr->args.numbers_of_philosophers);
	utils_ptr->last_meals_time = malloc(sizeof(long) * utils_ptr->args.numbers_of_philosophers);
	utils_ptr->end_simulation = malloc(sizeof(bool));
}
