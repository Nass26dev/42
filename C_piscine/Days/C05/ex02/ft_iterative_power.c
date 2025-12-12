/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:43:55 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/13 15:12:50 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	nb_init;

	nb_init = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= nb_init;
		power--;
	}
	return (nb);
}
/*int	main()
{
	printf("%d", ft_iterative_power(5,5));
}*/
