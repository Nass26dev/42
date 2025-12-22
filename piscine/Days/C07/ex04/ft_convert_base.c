/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:21:24 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/27 17:13:59 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);

int		ft_error_detector(char *base);

int		ft_check_in_base(char c, char *base);

int	ft_int_len(int nb, char *base)
{
	unsigned int	nbr;
	unsigned int	size_base;
	int				size;

	size = 0;
	nbr = nb;
	size_base = ft_strlen(base);
	if (nb < 0)
	{
		nbr = nb * -1;
		size++;
	}
	while (nbr >= size_base)
	{
		nbr /= size_base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int nb, char *base)
{
	unsigned int	nbr;
	char			*str;
	int				size;

	size = ft_int_len(nb, base);
	nbr = nb;
	str = malloc(size + 2);
	if (nb < 0)
	{
		nbr = nb * -1;
		str[0] = '-';
	}
	while (nbr >= (unsigned int)ft_strlen(base))
	{
		str[size] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		size--;
	}
	str[size] = base[nbr % ft_strlen(base)];
	size--;
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	i;
	long int	sign;
	long int	nb;
	long int	size_base;

	size_base = ft_strlen(base);
	i = 0;
	nb = 0;
	sign = 1;
	while (((9 <= str[i]) && (str[i] <= 13)) || str[i] == 32)
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (ft_check_in_base(str[i], base) != -1)
	{
		nb = nb * size_base + ft_check_in_base(str[i], base);
		i++;
	}
	return (nb * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*convert_from_b10;
	int		res_b10;

	if (ft_error_detector(base_from) == 1 || ft_strlen(base_from) <= 1)
		return (0);
	if (ft_error_detector(base_to) == 1 || ft_strlen(base_to) <= 1)
		return (0);
	res_b10 = ft_atoi_base(nbr, base_from);
	convert_from_b10 = ft_itoa_base(res_b10, base_to);
	return (convert_from_b10);
}
/*
{ char	*nbr;
	char	*base_f;
	char	*base_t;

	(void)argc;
	nbr = argv[1];
	base_f =  argv[2];
	base_t = argv[3];
	printf("%s",ft_convert_base(nbr, base_f, base_t));
}*/
