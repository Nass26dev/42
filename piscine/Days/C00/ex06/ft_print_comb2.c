/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:50 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/11 13:35:17 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_comb(void)
{
	write(1, " ", 1);
}

void	ft_if_end_comb(i, j)
{
	if (i != 98 || j != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putchar((i / 10) + '0');
			ft_putchar((i % 10) + '0');
			ft_write_comb();
			ft_putchar((j / 10) + '0');
			ft_putchar((j % 10) + '0');
			ft_if_end_comb(i, j);
			j++;
		}
		i++;
	}
}
/*int	main()
{
	ft_print_comb2();
}*/
