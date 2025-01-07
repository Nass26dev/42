/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_launcher_one_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:11:18 by nass              #+#    #+#             */
/*   Updated: 2024/12/14 12:48:38 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker/checker.h"

void	case_a_one_arg(char **splitted, int size)
{
	free_split(splitted, size);
	exit_program();
}

void	case_b_one_arg(t_stack *a, char **splitted, int size)
{
	while (a->top != -1)
		free(a->arr[a->top--]);
	free_split(splitted, size);
	free(a->arr);
	free(a);
	exit_program();
}

void	case_dup_one_arg(t_stack *a, t_stack *b, char **splitted, int size)
{
	free_all(a, b, size);
	free_split(splitted, size);
	exit_program();
}
