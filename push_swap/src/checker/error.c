/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:56:24 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/14 12:55:33 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker/checker.h"

t_error	is_only_num(int argc, char **argv)
{
	int	i;

	while (argc >= 1)
	{
		i = -1;
		if (argv[argc][0] == '-')
			i++;
		while (argv[argc][++i])
		{
			if (argv[argc][i] > '9' || argv[argc][i] < '0')
				return (ERROR);
		}
		argc--;
	}
	return (OK);
}

t_error	num_is_too_long(int argc, char **argv)
{
	while (argc >= 1)
	{
		if (ft_atol(argv[argc]) > INT_MAX)
			return (ERROR);
		if (ft_atol(argv[argc]) < INT_MIN)
			return (ERROR);
		argc--;
	}
	return (OK);
}

t_error	verif_one_arg(char *str)
{
	int		i;
	int		j;
	char	nb[12];

	i = -1;
	while (str[++i])
	{
		if (str[i] > '9' || (str[i] < '0' && str[i] != ' ' && str[i] != '-'))
			return (ERROR);
	}
	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i] == ' ')
			return (ERROR);
		if (str[i] == '-')
			nb[j++] = str[i++];
		while (str[i] <= '9' && str[i] >= '0')
			nb[j++] = str[i++];
		nb[j] = 0;
		if (ft_atol(nb) > INT_MAX && ft_atol(nb) < INT_MIN)
			return (ERROR);
	}
	return (OK);
}

t_error	verif(int argc, char **argv)
{
	if (!is_only_num(argc, argv))
		return (ERROR);
	if (!num_is_too_long(argc, argv))
		return (ERROR);
	return (OK);
}

t_error	is_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = a->top;
	while (i >= 0)
	{
		j = a->top;
		while (j >= 0)
		{
			if (j != i && a->arr[j]->value == a->arr[i]->value)
				return (ERROR);
			j--;
		}
		i--;
	}
	return (OK);
}
