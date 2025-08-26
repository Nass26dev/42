/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:33:25 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/22 02:52:09 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

bool	is_sorted(t_stack *a)
{
	int	temp;

	temp = a->top;
	while (temp > 0)
	{
		if (a->arr[temp]->value > a->arr[temp - 1]->value)
			return (false);
		temp--;
	}
	return (true);
}

bool	there_is_bigger(t_stack *b, int top)
{
	int	i;

	i = -1;
	while (++i <= b->top)
	{
		if (top < b->arr[i]->value)
			return (true);
	}
	return (false);
}
