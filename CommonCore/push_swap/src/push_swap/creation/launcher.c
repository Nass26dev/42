/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:20:01 by nass              #+#    #+#             */
/*   Updated: 2025/01/09 11:55:49 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"
#include "../../../include/push_swap/rules.h"

void	exit_program(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	main_function(t_stack *a, t_stack *b, t_stack *cpy, int size)
{
	push_swap_cpy(cpy, b);
	push_swap(a, b, cpy);
	free_all(a, b, cpy, size);
}

void	create_three_stacks(t_stack **a, t_stack **b, t_stack **cpy,
		char **splitted)
{
	int	size;

	size = 0;
	while (splitted[size])
		size++;
	*a = create_stack_one_arg(size, splitted);
	if (!*a)
		case_a_one_arg(splitted, size);
	*b = init_b_one_arg(size);
	if (!*b)
		case_b_one_arg(*a, splitted, size);
	*cpy = create_stack_one_arg(size, splitted);
	if (!*cpy)
		case_cpy_one_arg(*a, *b, splitted, size);
}

void	one_arg(char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*cpy;
	char	**splitted;
	int		size;

	a = NULL;
	b = NULL;
	cpy = NULL;
	if (!verif_one_arg(argv[1]))
		exit_program();
	splitted = ft_split(argv[1], ' ');
	if (!splitted)
		exit_program();
	size = 0;
	while (splitted[size])
		size++;
	create_three_stacks(&a, &b, &cpy, splitted);
	if (!is_duplicates(a))
	{
		free_split(splitted, size);
		case_dup_one_arg(a, b, cpy, size);
	}
	main_function(a, b, cpy, size);
	free_split(splitted, size);
}

void	several_args(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*cpy;

	if (!verif(argc - 1, argv))
		exit_program();
	a = create_stack(argc, argv);
	if (!a)
		exit_program();
	b = init_b(argc);
	if (!b)
		case_b(a);
	cpy = create_stack(argc, argv);
	if (!is_duplicates(a))
		case_dup(a, b, cpy, argc);
	main_function(a, b, cpy, argc);
}
