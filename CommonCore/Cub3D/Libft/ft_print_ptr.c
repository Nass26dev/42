/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:32:50 by tmarion           #+#    #+#             */
/*   Updated: 2025/01/13 16:25:50 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexptr(long long int ptr, char size)
{
	int	count;

	count = 0;
	if (ptr > 16)
	{
		ft_hexptr(ptr / 16, size);
		ft_hexptr(ptr % 16, size);
	}
	if (ptr <= 9)
		count += ft_putchar(ptr + 48);
	if (ptr >= 10 && ptr <= 16 && size == 'X')
		count += ft_putchar(ptr + 55);
	if (ptr >= 10 && ptr <= 16 && size == 'x')
		count += ft_putchar(ptr + 87);
	return (count);
}

int	ft_print_ptr(long long int ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	if (ptr > 0)
		count += ft_hexptr(ptr, 'X');
	return (count);
}

// int	main(void)
// {
// 	long long int	ptr;

// 	ptr = 0;
// 	ft_print_ptr(ptr);
// }