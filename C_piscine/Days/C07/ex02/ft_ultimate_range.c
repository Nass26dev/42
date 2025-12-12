/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:41:01 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/27 17:12:58 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	j;

	j = 0;
	i = min;
	if (min >= max)
		return (NULL);
	else
	{
		range = malloc((max - min) * sizeof(int) + 1);
		if (!range)
			return (range);
	}
	while (i < max)
	{
		range[j] = i;
		i++;
		j++;
	}
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*r;

	r = ft_range(min, max);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = r;
	return (max - min);
}
/*
int     ft_atoi(char *str)
{
        int     nb;
        int     sign;

        nb = 0;
        sign = 1;
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

void    ft_putnbr(int nb)
{
        int     nbr;

        if (nb == -2147483648)
        {
                write(1, "-2147483648", 11);
                return ;
        }
        else if (nb < 0)
        {
                write(1, "-", 1);
                ft_putnbr(nb * (-1));
        }
        else if (nb <= 9)
        {
                nb = nb + '0';
                write(1, &nb, 1);
        }
        else
        {
                nbr = nb % 10;
                nb = nb / 10;
                ft_putnbr(nb);
                nbr = nbr + '0';
                write(1, &nbr, 1);
        }
}

int main(int argc, char **argv)
{
        int int1 = ft_atoi(argv[1]);
        int int2 = ft_atoi(argv[2]);
	int	*range;
        int	taille = ft_ultimate_range(&range,int1,int2);
	int	i = 0;

	while (i < (int2 - int1))
	{
		ft_putnbr(range[i]);
		write(1,"\n",1);
		i++;
	}
	write(1, "taille : ", 9);
	ft_putnbr(taille);
}
*/
