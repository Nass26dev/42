/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:39:25 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/02 17:10:51 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_count	ft_unsigned_putnbr(unsigned int n, t_count *count)
{
	unsigned int	nbr;

	if (count->error == -1)
		return (*count);
	if (n <= 9)
		*count = ft_putchar(n + '0', *count);
	else
	{
		nbr = n % 10;
		n = n / 10;
		ft_putnbr(n, count);
		*count = ft_putchar(nbr + '0', *count);
	}
	return (*count);
}
