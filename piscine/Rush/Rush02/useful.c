/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:20 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/25 20:11:39 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

unsigned long long int	ft_atoi(char *str)
{
	unsigned long long int	nb;
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

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    unsigned long long int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
    }
}    

char	*ft_itoa(unsigned long long int nb)
{
	unsigned long long int	size;
	char	*str;
	unsigned long long int	nbr;
	unsigned long long int	nbr_cpy;
	unsigned long long int  i;

	size = 1;
	nbr = nb;
	nbr_cpy = nbr;
	while (nbr >= 10)
	{
		nbr = (nbr / 10);
		size++;
	}
	str = malloc(size * sizeof(char));
	i = size-1;
	while (nbr_cpy >= 10)
	{
		str[i] = nbr_cpy % 10 + '0';
		nbr_cpy = nbr_cpy / 10;
		i--;
	}
	if (nbr_cpy < 10)
	{
		str[i] = nbr_cpy % 10 + '0';
		i--;
	}
	return (str);
}

unsigned long long int	ft_recursive_power(unsigned long long int nb, unsigned long long int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
