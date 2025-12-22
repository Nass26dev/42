/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:09:32 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/29 16:26:23 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_in_hexadecimal(char c)
{
	char	*hexadecimal;

	hexadecimal = "0123456789abcdef";
	write(1, &hexadecimal[(unsigned char)c / 16], 1);
	write(1, &hexadecimal[(unsigned char)c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			ft_print_in_hexadecimal(*str);
			str++;
		}
		else
		{
			write(1, &*str, 1);
			str++;
		}
	}
}
/*
int main()
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
*/
