/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:07:40 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/23 02:07:40 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t nb)
{
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (nb > 0)
		{
			((unsigned char *)dest)[nb - 1] = ((unsigned char *)src)[nb - 1];
			nb--;
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, nb);
	return (dest);
}

/*int	main(void)
{
	char dst2[] = "0123456789";
    int size = 5;
    printf("ft_: %s\n", (char *)ft_memmove(dst2 + 3, dst2, size));
    printf("original: %s\n", (char *)memmove(dst2 + 3, dst2, size));
}*/