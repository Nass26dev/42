/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:26:22 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/29 15:33:04 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comparator(char *s1, char *s2, size_t nb)
{
	size_t	i;
	size_t	j;

	j = nb;
	i = 0;
	if (nb == 0)
		return (0);
	if (!s1 && !s2)
		return (0);
	while (i <= j - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	char	*cast1;
	char	*cast2;

	cast1 = (char *)p1;
	cast2 = (char *)p2;
	return (ft_comparator(cast1, cast2, size));
}

/*int	main(void)
{
	char *s1 = "teste";
	char *s2 = "teste";
	int	i = 0;

	printf("%d\n", ft_memcmp(s1, s2, i));
}*/
