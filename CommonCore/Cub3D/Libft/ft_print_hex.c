/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:14:45 by tmarion           #+#    #+#             */
/*   Updated: 2025/01/13 16:25:38 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexputnbr(unsigned int nb, char size, int count)
{
	if (nb >= 16)
	{
		ft_hexputnbr(nb / 16, size, count);
		ft_hexputnbr(nb % 16, size, count);
	}
	if (nb <= 9)
		count += ft_putchar(nb + 48);
	if (nb >= 10 && nb < 16 && size == 'X')
		count += ft_putchar(nb + 55);
	if (nb >= 10 && nb < 16 && size == 'x')
		count += ft_putchar(nb + 87);
	return (count);
}

int	ft_print_hex(unsigned int nb, char size)
{
	static int	count;
	int			temp;

	temp = 0;
	count += ft_hexputnbr(nb, size, count);
	temp = count;
	count = 0;
	return (temp);
}
