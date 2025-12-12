/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:10:16 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 10:27:09 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_rec_calc(int nb, int valeur)
{
	valeur *= nb--;
	if (nb > 0)
		return (ft_rec_calc(nb, valeur));
	return (valeur);
}

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (ft_rec_calc(nb, 1));
}

/*int main()
{
	printf("%d", ft_recursive_factorial(12));
}*/
