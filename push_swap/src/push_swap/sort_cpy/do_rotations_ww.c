/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotations_ww.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 02:20:34 by nass              #+#    #+#             */
/*   Updated: 2024/12/27 23:01:43 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"
#include "../../../include/push_swap/rules_ww.h"

void	rrr_or_rr_ww(t_stack *a, t_stack *b, int index_final, int index_big)
{
	int	element;
	int	target;

	element = b->arr[index_final]->value;
	target = a->arr[index_big]->value;
	while (b->arr[b->top]->value != element && a->arr[a->top]->value != target)
	{
		if (index_final < b->top / 2 && index_big < a->top / 2)
			rrr_ww(a, b);
		else if (index_final >= b->top / 2 && index_big >= a->top / 2)
			rr_ww(a, b);
		else
			break ;
	}
}

void	rra_or_ra_ww(t_stack *a, int target, int index_big)
{
	while (a->arr[a->top]->value != target)
	{
		if (index_big < a->top / 2)
			rra_ww(a);
		else
			ra_ww(a);
	}
}

void	rrb_or_rb_ww(t_stack *b, int element, int index_final)
{
	while (b->arr[b->top]->value != element)
	{
		if (index_final < b->top / 2)
			rrb_ww(b);
		else
			rb_ww(b);
	}
}

void	do_rotations_and_push_ww(t_stack *a, t_stack *b)
{
	int	index_final;
	int	index_big;
	int	element;
	int	target;

	index_final = cost_push(a, b);
	index_big = find_closest_biggest(b->arr[index_final]->value, a);
	element = b->arr[index_final]->value;
	target = a->arr[index_big]->value;
	rrr_or_rr_ww(a, b, index_final, index_big);
	rra_or_ra_ww(a, target, index_big);
	rrb_or_rb_ww(b, element, index_final);
	pa_ww(a, b);
}

void	final_rotations_ww(t_stack *a)
{
	int	min;

	min = 0;
	min = find_min(a);
	if (min < a->top / 2)
	{
		while (min >= 0)
		{
			rra_ww(a);
			min--;
		}
	}
	else
	{
		while (a->top - min > 0)
		{
			ra_ww(a);
			min++;
		}
	}
}
