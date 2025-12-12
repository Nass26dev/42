/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:27:21 by nass              #+#    #+#             */
/*   Updated: 2024/12/27 22:57:51 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap/push_swap.h"
#include "../../include/push_swap/rules.h"

void	rrr_or_rr(t_stack *a, t_stack *b, int index_final, int index_big)
{
	int	element;
	int	target;

	element = b->arr[index_final]->value;
	target = a->arr[index_big]->value;
	while (b->arr[b->top]->value != element && a->arr[a->top]->value != target)
	{
		if (index_final < b->top / 2 && index_big < a->top / 2)
			rrr(a, b);
		else if (index_final >= b->top / 2 && index_big >= a->top / 2)
			rr(a, b);
		else
			break ;
	}
}

void	rra_or_ra(t_stack *a, int target, int index_big)
{
	while (a->arr[a->top]->value != target)
	{
		if (index_big < a->top / 2)
			rra(a);
		else
			ra(a);
	}
}

void	rrb_or_rb(t_stack *b, int element, int index_final)
{
	while (b->arr[b->top]->value != element)
	{
		if (index_final < b->top / 2)
			rrb(b);
		else
			rb(b);
	}
}

void	do_rotations_and_push(t_stack *a, t_stack *b)
{
	int	index_final;
	int	index_big;
	int	element;
	int	target;

	index_final = cost_push(a, b);
	index_big = find_closest_biggest(b->arr[index_final]->value, a);
	element = b->arr[index_final]->value;
	target = a->arr[index_big]->value;
	rrr_or_rr(a, b, index_final, index_big);
	rra_or_ra(a, target, index_big);
	rrb_or_rb(b, element, index_final);
	pa(a, b);
}

void	final_rotations(t_stack *a)
{
	int	min;

	min = 0;
	min = find_min(a);
	if (min < a->top / 2)
	{
		while (min >= 0)
		{
			rra(a);
			min--;
		}
	}
	else
	{
		while (a->top - min > 0)
		{
			ra(a);
			min++;
		}
	}
}
