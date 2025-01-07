/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:26:02 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:51:49 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

void	cost_logic(t_stack *a, t_stack *b, t_variable *var, int i)
{
	int	index_big;

	if (i < b->top / 2)
		var->b_bot = i + 1;
	else
		var->b_top = b->top - i;
	index_big = find_closest_biggest(b->arr[i]->value, a);
	if (index_big < a->top / 2)
		var->a_bot = index_big + 1;
	else
		var->a_top = a->top - index_big;
}

int	cost_calc(t_variable *var)
{
	int	cost_final;

	cost_final = 0;
	if (var->a_top > var->b_top)
		cost_final += var->a_top;
	else if (var->a_top <= var->b_top)
		cost_final += var->b_top;
	if (var->a_bot > var->b_bot)
		cost_final += var->a_bot;
	else if (var->a_bot <= var->b_bot)
		cost_final += var->b_bot;
	return (cost_final);
}

int	cost_push(t_stack *a, t_stack *b)
{
	t_variable	var;
	int			i;
	int			index_final;
	int			min_cost;

	min_cost = INT_MAX;
	index_final = 0;
	i = b->top;
	while (i >= 0)
	{
		var.a_top = 0;
		var.b_top = 0;
		var.a_bot = 0;
		var.b_bot = 0;
		cost_logic(a, b, &var, i);
		if (cost_calc(&var) < min_cost)
		{
			min_cost = cost_calc(&var);
			index_final = i;
		}
		i--;
	}
	return (index_final);
}
