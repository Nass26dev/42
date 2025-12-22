/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:39:47 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/20 16:30:40 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt_calc(int nb, int nbr)
{
	if (nbr > nb)
		return (0);
	if ((nbr * nbr) == nb)
		return (nbr);
	else
		return (ft_sqrt_calc(nb, (nbr + 1)));
}

int	ft_sqrt(int nb)
{
	int	nbr;

	nbr = 1;
	if (nb < 0)
		return (0);
	else
		return (ft_sqrt_calc(nb, nbr));
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
	if (argc < 2)
	{
		printf("Entrez une valeur svp");
		return (1);
	}
	if (argc > 2)
	{
		printf("N'entrez qu'une seule valeur svp");
			return (1);
	}
	printf("%d", ft_sqrt(ft_atoi(argv[1])));
	return (0);
}*/
