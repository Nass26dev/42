/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ww.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:53:19 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:41:06 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap/rules_ww.h"

void	rra_ww(t_stack *a)
{
	int	temp;
	int	current;

	if (a->top == -1)
		return ;
	current = 0;
	temp = a->arr[0]->value;
	while (current < a->top)
	{
		a->arr[current]->value = a->arr[current + 1]->value;
		current++;
	}
	a->arr[a->top]->value = temp;
}

void	rrb_ww(t_stack *b)
{
	int	temp;
	int	current;

	if (b->top == -1)
		return ;
	current = 0;
	temp = b->arr[0]->value;
	while (current < b->top)
	{
		b->arr[current]->value = b->arr[current + 1]->value;
		current++;
	}
	b->arr[b->top]->value = temp;
}

void	rrr_ww(t_stack *a, t_stack *b)
{
	int	temp;
	int	current;

	if (a->top == -1 || b->top == -1)
		return ;
	current = 0;
	temp = a->arr[0]->value;
	while (current < a->top)
	{
		a->arr[current]->value = a->arr[current + 1]->value;
		current++;
	}
	a->arr[a->top]->value = temp;
	current = 0;
	temp = b->arr[0]->value;
	while (current < b->top)
	{
		b->arr[current]->value = b->arr[current + 1]->value;
		current++;
	}
	b->arr[b->top]->value = temp;
}
