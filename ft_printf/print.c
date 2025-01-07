/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:10:57 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/02 17:10:58 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_count	ft_putchar(char c, t_count count)
{
	count.error = write(1, &c, 1);
	count.nb += count.error;
	return (count);
}

t_count	ft_putstr(char *str, t_count count)
{
	if (!str)
	{
		count.error = write(1, "(null)", 6);
		count.nb += count.error;
		return (count);
	}
	count.error = write(1, str, ft_strlen(str));
	count.nb += count.error;
	return (count);
}

t_count	print_ptr(va_list args, t_count count)
{
	void	*temp;
	char	*str;

	temp = va_arg(args, void *);
	if (!temp)
	{
		count = ft_putstr("(nil)", count);
		return (count);
	}
	str = convert_base_16((unsigned long long int)temp, 'x');
	count = ft_putstr("0x", count);
	if (count.error == -1)
		return (count);
	count = ft_putstr(str, count);
	free(str);
	return (count);
}

t_count	print_in_hexa(va_list args, char c, t_count count)
{
	char	*str;

	str = convert_base_16((unsigned int)va_arg(args, int), c);
	count = ft_put_free_str(str, count);
	return (count);
}

t_count	ft_putnbr(int n, t_count *count)
{
	int	nbr;

	if (count->error == -1)
		return (*count);
	if (n == -2147483648)
	{
		*count = ft_putstr("-2147483648", *count);
		return (*count);
	}
	else if (n < 0)
	{
		*count = ft_putchar('-', *count);
		ft_putnbr(n * (-1), count);
	}
	else if (n <= 9)
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
