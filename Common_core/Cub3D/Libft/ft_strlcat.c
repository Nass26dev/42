/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft0_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:28:38 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/22 21:28:38 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	y;

	j = 0;
	y = 0;
	i = 0;
	if (!src || !size)
		return (j + ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	j = i;
	while (src[y] && i < size - 1)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	if (i < size)
		dst[i] = 0;
	return (j + ft_strlen(src));
}

/*int	main(void)
{
	int	size = 7;
	char s1[32] = "pqrstuvwxyz";
	char *s2 = "abcd";
	printf("ft_: %d\n", (int)ft_strlcat(s1, s2, size));
}*/