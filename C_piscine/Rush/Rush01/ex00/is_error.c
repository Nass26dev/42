/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:05:11 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 17:15:53 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_input_is_correct(char *str)
{
	int	i;
	int	j;

	j = ft_strlen(str);
	i = 0;
	if (j != 31)
		return (1);
	while (str[i])
	{
		if (str[i] == ' ')
		{
			if (str[i + 1] < '1' || str[i + 1] > '4')
				return (1);
		}
		if (str[i] != ' ' && str[i] < '1' || str[i] > '4')
			return (1);
		i++;
	}
	return (0);
}
