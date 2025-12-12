/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:05:27 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/21 10:23:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt * sqrt < nb)
		sqrt += 1;
	return (sqrt);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	sqrt = ft_sqrt(nb);
	i = 2;
	if (nb >= 2)
	{
		while (i <= sqrt)
		{
			if (nb % i == 0 && i != nb)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	while (ft_is_prime(nb + i) == 0)
		i++;
	return (nb + i);
}
/*
int     ft_atoi(char *str)
{
        int     nb;
        int     sign;

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

int main(int argc, char **argv)
{
        if (argc < 2 || argc > 2 )
        {
                if (argc < 2)
                        printf("Entrez une valeur svp");
                if (argc > 2)
                        printf("N'entrez qu'une seule valeur svp");
                return (1);
        }
        printf("%d", ft_find_next_prime(ft_atoi(argv[1])));
        return (0);
}*/
