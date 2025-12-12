/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:34:14 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/17 14:43:54 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_error(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = 0;
		count = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int		size_base;
	unsigned int		i;
	unsigned int		cpy_nbr;

	cpy_nbr = nbr;
	size_base = ft_strlen(base);
	i = 0;
	if (size_base <= 1 || ft_check_error(base) == 1 || base[0] == '\0')
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		cpy_nbr = nbr * (-1);
	}
	if (cpy_nbr >= size_base)
	{
		ft_putnbr_base(cpy_nbr / size_base, base);
	}
	i = cpy_nbr % size_base;
	ft_putchar(base[i]);
}

/*int	main(void)
{
	ft_putnbr_base(42, "0123456789abcdef");
}*/
