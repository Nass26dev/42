/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:03:33 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:51:20 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

t_stack	*init_b(int argc)
{
	t_stack	*b;
	int		temp;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->arr = malloc(argc * sizeof(t_node *));
	if (!b->arr)
		return (free(b), NULL);
	b->top = -1;
	temp = argc - 1;
	while (temp >= 0)
	{
		if (!add_to_stack(b, 0))
		{
			while (b->top != -1)
				free(b->arr[b->top--]);
			free(b->arr);
			free(b);
			return (NULL);
		}
		temp--;
	}
	b->top = -1;
	return (b);
}

t_stack	*init_b_one_arg(int argc)
{
	t_stack	*b;
	int		temp;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->arr = malloc(argc * sizeof(t_node *));
	if (!b->arr)
		return (free(b), NULL);
	b->top = -1;
	temp = argc - 1;
	while (temp >= 0)
	{
		if (!add_to_stack(b, 0))
		{
			while (b->top != -1)
				free(b->arr[b->top--]);
			free(b->arr);
			free(b);
			return (NULL);
		}
		temp--;
	}
	b->top = -1;
	return (b);
}
