/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:31:10 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/27 22:56:09 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap/push_swap.h"
#include "../../include/push_swap/rules.h"
#include "../../include/push_swap/rules_ww.h"

void	free_all(t_stack *a, t_stack *b, t_stack *cpy, int argc)
{
	int	temp;

	temp = argc - 1;
	while (temp >= 0)
	{
		free(a->arr[temp]);
		free(b->arr[temp]);
		free(cpy->arr[temp]);
		temp--;
	}
	free(a->arr);
	free(b->arr);
	free(cpy->arr);
	free(a);
	free(b);
	free(cpy);
}

void	push_swap_cpy(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	if (!is_sorted(a))
	{
		if (a->top == 1)
			sa_ww(a);
		else if (a->top == 2)
			three_sort_ww(a);
		else if (a->top == 3 || a->top == 4)
			sort_little_stacks_ww(a, b);
		else
			sort_cpy(a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b, t_stack *cpy)
{
	if (a->top == -1)
		return ;
	if (!is_sorted(a))
	{
		if (a->top == 1)
			sa(a);
		else if (a->top == 2)
			three_sort(a);
		else if (a->top == 3 || a->top == 4)
			little_stacks_sort(a, b);
		else
			sort(a, b, cpy);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
		one_arg(argv);
	else
		several_args(argc, argv);
	return (0);
}
