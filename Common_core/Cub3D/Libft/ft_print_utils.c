/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:39 by tmarion           #+#    #+#             */
/*   Updated: 2025/01/13 16:34:40 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	if (i != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		ft_putstr("(null)");
	i = write(1, s, ft_strlen(s));
	if (i != (int)ft_strlen(s))
		return (-1);
	return (i);
}
