/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:36:12 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/14 11:13:16 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(int n)
{
	int				nb;
	unsigned int	nbr;

	nb = 0;
	if (n < 0)
	{
		n = -n;
		nb++;
	}
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	if (nbr == 0)
		return (1);
	while (nbr >= 9)
	{
		nbr /= 10;
		nb++;
	}
	if (nbr > 0)
		return (nb + 1);
	return (nb);
}

char	*reverse_str(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = (ft_strlen(str) - 1);
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				i;

	i = -1;
	if (n >= 0)
		nb = n;
	else
		nb = -n;
	str = malloc(int_len(n) + 1);
	if (!str)
		return (NULL);
	while (nb > 9)
	{
		str[++i] = ((nb % 10) + '0');
		nb /= 10;
	}
	str[++i] = nb + '0';
	if (n < 0)
		str[++i] = '-';
	str[++i] = 0;
	return (reverse_str(str));
}
