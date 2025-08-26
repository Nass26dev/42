/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:22:41 by nass              #+#    #+#             */
/*   Updated: 2024/12/14 12:48:49 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker/checker.h"

void	case_b(t_stack *a)
{
	while (a->top != -1)
		free(a->arr[a->top--]);
	free(a->arr);
	free(a);
	exit_program();
}

void	case_dup(t_stack *a, t_stack *b, int argc)
{
	free_all(a, b, argc);
	exit_program();
}
