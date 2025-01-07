/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:59:53 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/22 03:30:01 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker/checker.h"
#include "../../include/checker/rules.h"

void	free_all(t_stack *a, t_stack *b, int argc)
{
	int	temp;

	temp = argc - 1;
	while (temp >= 0)
	{
		free(a->arr[temp]);
		free(b->arr[temp]);
		temp--;
	}
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0')
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
	}
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}

t_error	move(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(str, "sa\n"))
		sa(a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b);
	else
		return (ERROR);
	return (OK);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!move(a, b, str))
		{
			write(2, "Error\n", 6);
			return ;
		}
		free(str);
	}
	if (is_sorted(a) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
		checker_one_arg(argv);
	else
		checker_several_args(argc, argv);
	return (0);
}
