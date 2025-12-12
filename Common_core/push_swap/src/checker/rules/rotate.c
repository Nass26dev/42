/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:13:22 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 17:50:03 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker/rules.h"

void	ra(t_stack *a)
{
	int	temp;
	int	current;

	if (a->top == -1)
		return ;
	current = a->top;
	temp = a->arr[a->top]->value;
	while (current > 0)
	{
		a->arr[current]->value = a->arr[current - 1]->value;
		current--;
	}
	a->arr[0]->value = temp;
}

void	rb(t_stack *b)
{
	int	temp;
	int	current;

	if (b->top == -1)
		return ;
	current = b->top;
	temp = b->arr[b->top]->value;
	while (current > 0)
	{
		b->arr[current]->value = b->arr[current - 1]->value;
		current--;
	}
	b->arr[0]->value = temp;
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	current;

	if (a->top == -1 || b->top == -1)
		return ;
	current = a->top;
	temp = a->arr[a->top]->value;
	while (current > 0)
	{
		a->arr[current]->value = a->arr[current - 1]->value;
		current--;
	}
	a->arr[0]->value = temp;
	current = b->top;
	temp = b->arr[b->top]->value;
	while (current > 0)
	{
		b->arr[current]->value = b->arr[current - 1]->value;
		current--;
	}
	b->arr[0]->value = temp;
}
