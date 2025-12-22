/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:54:58 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/27 23:02:34 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"
#include "../../../include/push_swap/rules_ww.h"

void	three_sort_ww(t_stack *a)
{
	int	big;
	int	ind_big;

	ind_big = find_max(a);
	big = a->arr[ind_big]->value;
	if (a->arr[a->top]->value == big)
		ra_ww(a);
	else if (a->arr[a->top - 1]->value == big)
		rra_ww(a);
	if (a->arr[a->top - 1]->value < a->arr[a->top]->value)
		sa_ww(a);
}

void	sort_little_stacks_ww(t_stack *a, t_stack *b)
{
	int	target;

	while (a->top != 2)
	{
		target = find_smallest(a);
		if (find_quickest_path(a, target))
		{
			while (target != a->arr[a->top]->value)
				ra_ww(a);
		}
		else
		{
			while (target != a->arr[a->top]->value)
				rra_ww(a);
		}
		pb_ww(a, b);
	}
	three_sort_ww(a);
	while (b->top != -1)
		pa_ww(a, b);
}

void	sort_cpy(t_stack *cpy, t_stack *b)
{
	while (cpy->top > 2)
		pb_ww(cpy, b);
	three_sort_ww(cpy);
	while (b->top != -1)
		do_rotations_and_push_ww(cpy, b);
	final_rotations_ww(cpy);
}
