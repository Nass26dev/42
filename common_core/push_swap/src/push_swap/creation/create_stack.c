/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:48:40 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/09 11:54:45 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

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
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

t_error	add_to_stack(t_stack *a, int nb)
{
	a->top++;
	a->arr[a->top] = malloc(sizeof(t_node));
	if (!a->arr[a->top])
		return (ERROR);
	a->arr[a->top]->value = nb;
	return (OK);
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*a;
	int		temp;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->arr = malloc(argc * sizeof(t_node *));
	if (!a->arr)
		return (free(a), NULL);
	a->top = -1;
	temp = argc - 1;
	while (temp >= 1)
	{
		if (!add_to_stack(a, ft_atol(argv[temp--])))
		{
			while (a->top != -1)
				free(a->arr[a->top--]);
			free(a->arr);
			free(a);
			return (NULL);
		}
	}
	return (a);
}

t_stack	*create_stack_one_arg(int argc, char **argv)
{
	t_stack	*a;
	int		temp;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->arr = malloc(argc * sizeof(t_node *));
	if (!a->arr)
		return (free(a), NULL);
	a->top = -1;
	temp = argc - 1;
	while (temp >= 0)
	{
		if (!add_to_stack(a, ft_atol(argv[temp--])))
		{
			while (a->top != -1)
				free(a->arr[a->top--]);
			free(a->arr);
			free(a);
			return (NULL);
		}
	}
	return (a);
}
