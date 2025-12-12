/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:20 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 16:38:05 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*str++ - 48);
	return (nb * sign);
}
/*int main()
{
	char str[] = "   -++------fqf1234ab414";

	printf("%d", ft_atoi(str));
}*/
