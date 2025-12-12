/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:50:59 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/08 11:24:33 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		nbr = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		nbr = nbr + '0';
		write(fd, &nbr, 1);
	}
}
