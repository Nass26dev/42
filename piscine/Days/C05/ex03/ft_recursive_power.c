/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:21:00 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/20 18:50:16 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_calc(int nb, int power, int init)
{
	nb *= init;
	power--;
	if (power > 1)
		return (ft_recursive_calc(nb, power, init));
	return (nb);
}

int	ft_recursive_power(int nb, int power)
{
	int	init;

	init = nb;
	if (nb < 0)
		return (0);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	return (ft_recursive_calc(nb, power, init));
}
/*
int main()
{
	printf("%d", ft_recursive_power(5,0));
}*/
