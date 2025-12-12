/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:53:29 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/11 13:36:55 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	nbr;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * (-1));
	}
	else if (nb <= 9)
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
	else
	{
		nbr = nb % 10;
		nb = nb / 10;
		ft_putnbr(nb);
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
}
/*int main()
{
	ft_putnbr(-42);
}*/
