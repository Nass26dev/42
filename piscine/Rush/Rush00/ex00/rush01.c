/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:12:55 by paubello          #+#    #+#             */
/*   Updated: 2024/08/11 20:34:01 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_drawline(int x, int y, int line)
{
	int		column;
	char	sign;

	column = 0;
	while (column < x)
	{
		sign = ' ';
		if ((line == 0 || line == y - 1) || (column == 0 || column == x - 1))
			sign = '*';
		if ((line == 0 && column == x - 1) || (line == y - 1 && column == 0))
			sign = 92;
		if ((line == 0 && column == 0)
			|| (line == y - 1 && column == x - 1 && x > 1 && y > 1))
			sign = '/';
		ft_putchar(sign);
		column++;
	}
}

void	rush(int x, int y)
{
	int	line;

	line = 0;
	if (x <= 0 || y <= 0)
	{
		write(1, "Pass values between 1 and 2147483647", 38);
		return ;
	}
	while (line < y)
	{
		ft_drawline(x, y, line);
		ft_putchar('\n');
		line++;
	}
}
