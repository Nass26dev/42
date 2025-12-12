/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:56:42 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/24 11:34:48 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

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
			return (NULL);
	}
	while (i < max)
	{
		range[j] = i;
		i++;
		j++;
	}
	return (range);
}
/*
int main(int argc, char **argv)
{
	int int1 = ft_atoi(argv[1]);
	int int2 = ft_atoi(argv[2]);
	int *tab = ft_range(int1,int2);
	int	i = 0;

	if (ft_range(int1,int2) != NULL)
		while (tab[i] != '\0')
		{
			printf("%d", tab[i]);
			if (tab[i + 1] != '\0')
				printf(" ,");
			i++;
		}
	else
		printf("NULL");
}*/
