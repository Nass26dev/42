/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:10:19 by dozo              #+#    #+#             */
/*   Updated: 2025/01/13 16:26:03 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_which_one(va_list args, const char this)
{
	int	len;

	len = 0;
	if (this == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (this == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (this == 'd' || this == 'i')
		len += ft_print_ultimate(va_arg(args, int));
	else if (this == '%')
		len += ft_putchar('%');
	else if (this == 'u')
		len += ft_print_ultimate(va_arg(args, unsigned int));
	else if (this == 'x' || this == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), this);
	else if (this == 'p')
		len += ft_print_ptr(va_arg(args, long long int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_which_one(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	char c = 'c';
// 	char *s = NULL;
// 	int d = 123;
// 	int i = 123;
// 	unsigned int u = 1234;
// 	int x = 42;
// 	int X = 42;
// 	int *ptr = &d;
// 	char test[] = "prout, %c, %s, %p, %d, %i, %u, %x, %X, %%, prout";
// 	ft_printf(test, c, NULL, ptr, d, i, u, x, X);
// 	write(1, "\n", 1);
// 	printf("fart, %c, %s, %p, %d, %i, %u, %x, %X, %%, 
//fart", c, s, ptr, d, i, u, x, X);
// 	return (0);
// }
