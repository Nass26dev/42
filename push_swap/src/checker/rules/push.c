/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:45:00 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 17:49:54 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker/rules.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->arr[++a->top]->value = b->arr[b->top--]->value;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->arr[++b->top]->value = a->arr[a->top--]->value;
}
