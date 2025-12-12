/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:29:23 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/28 14:29:23 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *source, int neww, size_t nb)
{
	size_t	i;
	char	*src;

	i = 0;
	src = (char *)source;
	while (i < nb)
	{
		src[i] = neww;
		i++;
	}
	return (source);
}

/*int	main(void)
{
	int	i = 258;
	int	j =5;
	char s1[] = "0000000000";
	//char s2[] = "";

	printf("ft_: %s\n", (char *)ft_memset(s1, i, j));
	printf("original: %s\n",(char *)memset(s1, i, j));
}*/