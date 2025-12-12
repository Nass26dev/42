/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:45:00 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/20 17:55:47 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/rules.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->arr[++a->top]->value = b->arr[b->top--]->value;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->arr[++b->top]->value = a->arr[a->top--]->value;
	write(1, "pb\n", 3);
}
