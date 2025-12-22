/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:39:25 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/25 20:10:14 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

unsigned long long int	ft_strstr(char *str, char *to_find)
{
	unsigned long long int	i;
	unsigned long long int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	find_print(char *parsing_str, char *nb_str)
{
	unsigned long long int i;
	unsigned long long int start;
	unsigned long long int size;

	i = 0;
	size = ft_strlen(nb_str);
	start = ft_strstr(parsing_str, nb_str);
	while (!(parsing_str[start] >= 'a' && parsing_str[start] <= 'z'))
	{
		start++;
	}
	while (parsing_str[start] >= 'a' && parsing_str[start] <= 'z')
	{
		ft_putchar(parsing_str[start]);
		start++;
	}
	if (size > 0)
		ft_putchar(' ');
	size--;
	i++;
}

void	index_base(char *nb_str, char *parse)
{
	unsigned long long int i;
	unsigned long long int j;
	unsigned long long int size;
	unsigned long long int nbr;
	unsigned long long int large_nbr;
	char *str_l_index;
	char *str_index;
	int mod_j;

	size = ft_strlen(nb_str);
	j = size - 1;
	i = 0;
	while (nb_str[i])
	{
		nbr = nb_str[i] - '0';
		mod_j = j % 3;
		if (mod_j == 1)
        	{
			large_nbr = nbr * ft_recursive_power(10,1);
			str_index = ft_itoa(large_nbr);
			find_print(parse, str_index);
        	}
		else if (mod_j == 0 && j != 0)
		{
			str_l_index = ft_itoa(nbr);
			find_print(parse, str_l_index);
			large_nbr = ft_recursive_power(10, j);
			str_index = ft_itoa(large_nbr);
			find_print(parse, str_index);
		}
		else if ((mod_j >= 2 && mod_j <= 3))
		{
			str_l_index = ft_itoa(nbr);
			find_print(parse, str_l_index);
			large_nbr = ft_recursive_power(10, mod_j);
			str_index = ft_itoa(large_nbr);
			find_print(parse, str_index);
		}
		else if(mod_j == 0 && j == 0)
		{
			str_l_index = ft_itoa(nbr);
			find_print(parse, str_l_index);
		}
		j--;
		i++;
	}
}
