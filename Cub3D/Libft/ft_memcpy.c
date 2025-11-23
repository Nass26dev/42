/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:29:13 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/28 14:29:13 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nb)
{
	unsigned int		i;
	char				*castsrc;
	char				*castdest;

	castdest = (char *)dest;
	castsrc = (char *)src;
	if ((!dest && !src) && nb)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		castdest[i] = castsrc[i];
		i++;
	}
	return (castdest);
}
