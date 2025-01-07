/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ww.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:54:09 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:41:16 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap/rules_ww.h"

void	sa_ww(t_stack *a)
{
	int	temp;

	if (a->top == -1)
		return ;
	temp = a->arr[a->top]->value;
	a->arr[a->top]->value = a->arr[a->top - 1]->value;
	a->arr[a->top - 1]->value = temp;
}

void	sb_ww(t_stack *b)
{
	int	temp;

	if (b->top == -1)
		return ;
	temp = b->arr[b->top]->value;
	b->arr[b->top]->value = b->arr[b->top - 1]->value;
	b->arr[b->top - 1]->value = temp;
}

void	ss_ww(t_stack *a, t_stack *b)
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
