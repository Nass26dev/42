/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:30:55 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 17:25:27 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

void free_lst(t_list *lst, int exit_code)
{
    t_list 	*current;
	t_list	*next;
	
	current = lst;
    while (current)
	{
		next = current->next;
        free(current);
        current = next;
    }
    exit(exit_code);
}

void	recup_args(t_args *args, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (i == 1)
			args->numbers_of_philosophers = ft_atol(argv[i]);
		else if (i == 2)
			args->time_to_die = ft_atol(argv[i]);
		else if (i == 3)
			args->time_to_eat = ft_atol(argv[i]);
		else if (i == 4)
			args->time_to_sleep = ft_atol(argv[i]);
		if (i == 5 && argv[i])
		{
			args->max_meals = ft_atol(argv[i]);
			args->is_max_meals = true;
		}
		else
			args->is_max_meals = false;
	}
}

void	create_a_philo(t_list **lst, t_args args, int i)
{
	t_list	*new;
	t_list	*current;
	
	new = malloc(sizeof(t_list));
	if (!new)
		free_lst(*lst, 1);
	new->philo.id = i + 1;
	new->philo.time_to_die = args.time_to_die;
	new->philo.time_to_eat = args.time_to_eat;
	new->philo.time_to_sleep = args.time_to_sleep;
	new->philo.last_meal_time = get_current_time_ms();
	if (args.is_max_meals)
	{
		new->philo.is_max_meals = args.is_max_meals;
		new->philo.max_meals = args.max_meals;
	}
	current = *lst;
	if (!current)
		*lst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_list	*create_philosophers(int argc, char **argv)
{
	t_list	*lst;
	t_args	args;
	int		i;

	lst = NULL;
	i = -1;
	recup_args(&args, argc, argv);
	while (++i < args.numbers_of_philosophers)
		create_a_philo(&lst, args, i);
	return (lst);
}
