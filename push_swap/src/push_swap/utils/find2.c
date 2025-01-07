/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:18:34 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:52:01 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

int	find_max(t_stack *b)
{
	int	i;
	int	big;
	int	index_max;

	i = 0;
	big = 0;
	while (i <= b->top)
	{
		if (big < b->arr[i]->value)
		{
			big = b->arr[i]->value;
			index_max = i;
		}
		i++;
	}
	return (index_max);
}

int	find_min(t_stack *a)
{
	int	i;
	int	min;
	int	index_min;

	i = 0;
	min = INT_MAX;
	while (i <= a->top)
	{
		if (min > a->arr[i]->value)
		{
			min = a->arr[i]->value;
			index_min = i;
		}
		i++;
	}
	return (index_min);
}

int	find_closest_biggest(int value, t_stack *a)
{
	int	min_dif;
	int	i;
	int	index_biggest;

	min_dif = INT_MAX;
	i = 0;
	while (i <= a->top)
	{
		if (value < a->arr[i]->value && a->arr[i]->value - value < min_dif)
		{
			min_dif = a->arr[i]->value - value;
			index_biggest = i;
		}
		i++;
	}
	if (min_dif == INT_MAX)
		return (find_min(a));
	return (index_biggest);
}

int	find_closest_smallest(int value, t_stack *b)
{
	int	min_dif;
	int	i;
	int	index_smallest;

	min_dif = INT_MAX;
	i = 0;
	while (i <= b->top)
	{
		if (value > b->arr[i]->value && value - b->arr[i]->value < min_dif)
		{
			min_dif = value - b->arr[i]->value;
			index_smallest = i;
		}
		i++;
	}
	if (min_dif == INT_MAX)
		return (find_max(b));
	return (index_smallest);
}
