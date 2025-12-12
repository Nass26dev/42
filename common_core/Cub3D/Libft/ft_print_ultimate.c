/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:50:09 by tmarion           #+#    #+#             */
/*   Updated: 2025/01/13 16:25:57 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longlen(long long int nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		nb = nb * (-1);
		count++;
	}
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*ft_litoa(long long int n)
{
	int		i;
	char	*numb;

	i = ft_longlen(n);
	numb = malloc(sizeof(char) * i + 1);
	if (!numb)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		numb[0] = '-';
	}
	numb[i] = '\0';
	i--;
	while (n && i >= 0)
	{
		numb[i] = (n % 10) + 48;
		i--;
		n = n / 10;
	}
	return (numb);
}

int	ft_print_ultimate(long long int n)
{
	char	*nb;
	int		count;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		nb = ft_litoa(n);
		count += ft_putstr(nb);
		free (nb);
	}
	return (count);
}
// int	main(void)
// {
// 	long long int	d = -2147483647;
// 	long long int	u = 4294967295;

// 	ft_print_ultimate(d);
// 	write(1, "\n", 1);
// 	ft_print_ultimate(u);
// }