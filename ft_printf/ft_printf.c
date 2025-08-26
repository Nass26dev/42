/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:11:03 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/02 18:02:00 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_count	count_init(void)
{
	t_count	count;

	count.i = -1;
	count.nb = 0;
	count.error = 0;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	t_count	count;

	va_list(args);
	if (!str)
		return (-1);
	va_start(args, str);
	count = count_init();
	while (str[++count.i])
	{
		if (str[count.i] == '%' && str[count.i + 1])
		{
			if (char_is_flag(str[count.i + 1]))
				count = select_function(args, count, (char *)str);
		}
		else if ((str[count.i] == '%' && !str[count.i + 1]))
			return (-1);
		else
			count = ft_putchar(str[count.i], count);
		if (count.error == -1)
			return (-1);
	}
	va_end(args);
	return (count.nb);
}
