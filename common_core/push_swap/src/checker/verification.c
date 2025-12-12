/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:23:29 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 17:33:12 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker/checker.h"

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
