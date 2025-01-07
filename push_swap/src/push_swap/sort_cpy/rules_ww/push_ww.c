/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ww.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:52:43 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:41:01 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap/rules_ww.h"

void	pa_ww(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->arr[++a->top]->value = b->arr[b->top--]->value;
}

void	pb_ww(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->arr[++b->top]->value = a->arr[a->top--]->value;
}
