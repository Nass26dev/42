/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:35:15 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/22 02:51:56 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

int	find_biggest(t_stack *a)
{
	int	temp;
	int	max;

	if (a->top == -1)
		return (-1);
	max = INT_MIN;
	temp = -1;
	while (++temp <= a->top)
	{
		if (max < a->arr[temp]->value)
			max = a->arr[temp]->value;
	}
	return (max);
}

int	find_smallest(t_stack *a)
{
	int	temp;
	int	min;

	if (a->top == -1)
		return (-1);
	min = INT_MAX;
	temp = -1;
	while (++temp <= a->top)
	{
		if (min > a->arr[temp]->value)
			min = a->arr[temp]->value;
	}
	return (min);
}

int	find_quickest_path(t_stack *b, int search)
{
	int	rot_up;
	int	rot_down;

	if (b->top == -1)
		return (-1);
	rot_up = -1;
	while (++rot_up <= b->top)
	{
		if (b->arr[rot_up]->value == search)
			break ;
	}
	rot_down = b->top - (rot_up + 1);
	if (rot_up <= rot_down)
		return (0);
	return (1);
}

int	find_next_bigger(t_stack *b, int top)
{
	int	i;
	int	next;

	next = INT_MAX;
	i = -1;
	while (++i <= b->top)
	{
		if (next > b->arr[i]->value && b->arr[i]->value > top)
			next = b->arr[i]->value;
	}
	return (next);
}

int	find_smallest_path(t_stack *a)
{
	int	i;
	int	j;
	int	min;

	min = a->arr[a->top]->path;
	i = a->top;
	j = i;
	while (i >= 0)
	{
		if (min > a->arr[i]->path)
		{
			min = a->arr[i]->path;
			j = i;
		}
		i--;
	}
	return (j);
}
