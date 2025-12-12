/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:26:05 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 10:26:18 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	valeur;
	int	nbr;

	nbr = 0;
	valeur = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		valeur = valeur * nb;
		nb--;
	}
	return (valeur);
}

/*int main()
{
	printf("%d", ft_iterative_factorial(12));
}*/
