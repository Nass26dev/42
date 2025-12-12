/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:26:32 by nass              #+#    #+#             */
/*   Updated: 2024/12/27 22:58:35 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap/push_swap.h"
#include "../../include/push_swap/rules.h"

void	three_sort(t_stack *a)
{
	int	big;
	int	ind_big;

	ind_big = find_max(a);
	big = a->arr[ind_big]->value;
	if (a->arr[a->top]->value == big)
		ra(a);
	else if (a->arr[a->top - 1]->value == big)
		rra(a);
	if (a->arr[a->top - 1]->value < a->arr[a->top]->value)
		sa(a);
}

void	little_stacks_sort(t_stack *a, t_stack *b)
{
	int	target;

	while (a->top != 2)
	{
		target = find_smallest(a);
		if (find_quickest_path(a, target))
		{
			while (target != a->arr[a->top]->value)
				ra(a);
		}
		else
		{
			while (target != a->arr[a->top]->value)
				rra(a);
		}
		pb(a, b);
	}
	three_sort(a);
	while (b->top != -1)
		pa(a, b);
}

void	sort(t_stack *a, t_stack *b, t_stack *cpy)
{
	int	median;

	if (cpy->top % 2 == 0)
		median = cpy->arr[cpy->top / 2 + 1]->value;
	else
		median = cpy->arr[cpy->top / 2]->value;
	while (b->top < a->top)
	{
		if (median > a->arr[a->top]->value)
			ra(a);
		else
			pb(a, b);
	}
	while (a->top > 2)
		pb(a, b);
	three_sort(a);
	while (b->top != -1)
		do_rotations_and_push(a, b);
	final_rotations(a);
}
