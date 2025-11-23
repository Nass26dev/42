/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:47 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/29 15:15:10 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
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

char	*ft_itoa(int n)
{
	int		i;
	char	*numb;

	i = ft_len(n);
	numb = (char *)malloc(sizeof(char) * i + 1);
	if (!numb)
		return (NULL);
	if (n == -2147483648 && ft_strlcpy(numb, "-2147483648", i + 1))
		return (numb);
	if (n < 0)
	{
		n = n * (-1);
		numb[0] = '-';
	}
	if (n == 0)
		numb[0] = 48;
	numb[i] = 0;
	while (n && numb[i - 1] != '-')
	{
		numb[i - 1] = (n % 10) + 48;
		i--;
		n = n / 10;
	}
	return (numb);
}

/*int	main(void)
{
int i = -2147483648;
printf("%s\n", ft_itoa(i));
}*/