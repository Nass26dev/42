/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:00:18 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/07 17:51:33 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c, char d, char u)
{
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, &u, 1);
}

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = '0';
	while (c <= '7')
	{
		d = c + 1;
		while (d <= '8')
		{
			u = d + 1;
			while (u <= '9')
			{
				ft_putchar (c, d, u);
				if (c < '7' || d < '8' || u < '9')
				{
					write(1, ", ", 2);
				}
				u++;
			}
			d++;
		}
		c++;
	}
}
/*int main(void)
{
	ft_print_comb();
}*/
