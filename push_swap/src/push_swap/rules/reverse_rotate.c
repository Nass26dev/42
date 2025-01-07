/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:13:22 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/20 17:56:11 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/rules.h"

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
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
	write(1, "rrr\n", 4);
}
