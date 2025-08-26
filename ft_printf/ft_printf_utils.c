/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:11:10 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/02 17:50:13 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	char_is_flag(char c)
{
	char	*flags;

	flags = "cspdiuxX%";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

t_count	select_function(va_list args, t_count count, char *str)
{
	if (str[++count.i] == 'd' || str[count.i] == 'i')
		ft_putnbr(va_arg(args, int), &count);
	if (str[count.i] == 'c')
		count = ft_putchar(va_arg(args, int), count);
	else if (str[count.i] == 's')
		count = ft_putstr(va_arg(args, char *), count);
	else if (str[count.i] == 'p')
		count = print_ptr(args, count);
	else if (str[count.i] == 'u')
		ft_unsigned_putnbr(va_arg(args, int), &count);
	else if (str[count.i] == 'x' || str[count.i] == 'X')
		count = print_in_hexa(args, str[count.i], count);
	else if (str[count.i] == '%')
		count = ft_putchar('%', count);
	return (count);
}

char	*convert_base_16(unsigned long long int nb, char c)
{
	char	*hexa;
	char	*str;
	int		i;

	i = 0;
	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	str = malloc(buffer_len(nb) + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[i++] = '0';
	while (nb > 0)
	{
		str[i++] = hexa[nb % 16];
		nb /= 16;
	}
	str[i] = 0;
	return (reverse_str(str));
}
