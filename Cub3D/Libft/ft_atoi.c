/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:58 by tmarion           #+#    #+#             */
/*   Updated: 2025/10/30 12:45:38 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = sign * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		a = a * 10 + (str[i] - 48);
		i++;
	}
	if (i == 0)
		return (-1);
	return (a * sign);
}

/*int	main(void)
{
	char i[] = "\t\v\f\r\n \f-06050";
	
	printf("%d\n", ft_atoi(i));
}*/