/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:42:38 by maballet          #+#    #+#             */
/*   Updated: 2024/08/25 20:12:39 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_condition_01(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (2);
		i++;
	}
	if (ft_strlen(str) > 37)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

int	ft_condition_02(char *s1, char *s2)
{
	int	i;
	int	j;

	j = ft_strlen(s1) - 1;
	i = 0;
	if (s1[j] != 't' && s1[j - 1] != 'c'
			&& s1[j - 2] != 'i'
			&& s1[j - 3] != 'd'
			&& s1[j - 4] != '.')
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	while (s2[i])
	{
		if (s2[i] < '0' || s2[i] > '9')
			return (2);
		i++;
	}
	if (ft_strlen(s2) > 37)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	unsigned long long int	j;
	unsigned long long int	nbr;
	char	*nb;
	char	*parse_str;

	j = 1;
	if (argc > 3 || argc < 2)
	{
		write(1, "* 1 or 2 argument expected *", 29);
		return (1);
	}
	else if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		if (nbr < 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		nb = ft_itoa(nbr);
		if (ft_condition_01(nb) == 1 || ft_condition_01(nb) == 2)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		parse_str = ft_dict_opener("numbers.dict");
		index_base(nb, parse_str);
	}
	else if (argc == 3)
	{
		nbr = ft_atoi(argv[2]);
		if (nbr < 0)
		{
                        write(1, "Error\n", 6);
                        return (1);
                }
                nb = ft_itoa(nbr);
		if ((ft_condition_02(argv[j], nb)) == 1 || (ft_condition_02(argv[j], nb) == 2))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		parse_str = ft_dict_opener(argv[1]);
		if (parse_str == 0)
		{
			write(1, "invalid files", 13);
			return (0);
		}
		index_base(nb, parse_str);
	}
	return (0);
}
