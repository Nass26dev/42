/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:36:34 by nass              #+#    #+#             */
/*   Updated: 2024/12/22 02:51:16 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

void	case_b(t_stack *a)
{
	while (a->top != -1)
		free(a->arr[a->top--]);
	free(a->arr);
	free(a);
	exit_program();
}

void	case_cpy(t_stack *a, t_stack *b)
{
	while (a->top != -1)
	{
		free(b->arr[a->top]);
		free(a->arr[a->top--]);
	}
	free(a->arr);
	free(b->arr);
	free(b);
	free(a);
	exit_program();
}

void	case_dup(t_stack *a, t_stack *b, t_stack *cpy, int argc)
{
	free_all(a, b, cpy, argc);
	exit_program();
}
