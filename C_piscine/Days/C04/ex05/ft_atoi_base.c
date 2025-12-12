/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:04:21 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/22 15:31:31 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_detector(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (((9 <= base[i]) && (base[i] <= 13)) || base[i] == 32)
			return (1);
		j = 0;
		count = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	i;
	long int	sign;
	long int	nb;
	long int	size_base;

	size_base = ft_strlen(base);
	if (error_detector(base) == 1 || size_base <= 1)
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
	while (((9 <= str[i]) && (str[i] <= 13)) || str[i] == 32)
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (ft_check_in_base(str[i], base) != -1)
	{
		nb = nb * size_base + ft_check_in_base(str[i], base);
		i++;
	}
	return (nb * sign);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_atoi_base("2a", "0123456789abcdef"));
}
*/
