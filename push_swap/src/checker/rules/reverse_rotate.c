/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:13:22 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 17:49:49 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker/rules.h"

void	rra(t_stack *a)
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

void	rrb(t_stack *b)
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

void	rrr(t_stack *a, t_stack *b)
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
