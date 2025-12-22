/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:29:19 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/20 17:56:54 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/rules.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top == -1)
		return ;
	temp = a->arr[a->top]->value;
	a->arr[a->top]->value = a->arr[a->top - 1]->value;
	a->arr[a->top - 1]->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->top == -1)
		return ;
	temp = b->arr[b->top]->value;
	b->arr[b->top]->value = b->arr[b->top - 1]->value;
	b->arr[b->top - 1]->value = temp;
	write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
}
