/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ww.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:53:38 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:41:11 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap/rules_ww.h"

void	ra_ww(t_stack *a)
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

void	rb_ww(t_stack *b)
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

void	rr_ww(t_stack *a, t_stack *b)
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
