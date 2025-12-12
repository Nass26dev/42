/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:03:04 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/14 12:48:55 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker/checker.h"

void	exit_program(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	checker_one_arg(char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**splitted;
	int		size;

	if (!verif_one_arg(argv[1]))
		exit_program();
	splitted = ft_split(argv[1], ' ');
	if (!splitted)
		exit_program();
	size = 0;
	while (splitted[size])
		size++;
	a = create_stack_one_arg(size, splitted);
	if (!a)
		case_a_one_arg(splitted, size);
	b = init_b_one_arg(size);
	if (!b)
		case_b_one_arg(a, splitted, size);
	if (!is_duplicates(a))
		case_dup_one_arg(a, b, splitted, size);
	checker(a, b);
	free_all(a, b, size);
	free_split(splitted, size);
}

void	checker_several_args(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!verif(argc - 1, argv))
		exit_program();
	a = create_stack(argc, argv);
	if (!a)
		exit_program();
	b = init_b(argc);
	if (!b)
		case_b(a);
	if (!is_duplicates(a))
		case_dup(a, b, argc);
	checker(a, b);
	free_all(a, b, argc);
}
