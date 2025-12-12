/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:29:19 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 17:50:12 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker/rules.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top == -1)
		return ;
	temp = a->arr[a->top]->value;
	a->arr[a->top]->value = a->arr[a->top - 1]->value;
	a->arr[a->top - 1]->value = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->top == -1)
		return ;
	temp = b->arr[b->top]->value;
	b->arr[b->top]->value = b->arr[b->top - 1]->value;
	b->arr[b->top - 1]->value = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->top == -1 || b->top == -1)
		return ;
	temp = a->arr[a->top]->value;
	a->arr[a->top]->value = a->arr[a->top - 1]->value;
	a->arr[a->top - 1]->value = temp;
	temp = b->arr[b->top]->value;
	b->arr[b->top]->value = b->arr[b->top - 1]->value;
	b->arr[b->top - 1]->value = temp;
}
