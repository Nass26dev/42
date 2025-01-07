/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:51:34 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/23 17:06:42 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptrsrc;

	if (!src && !dest && n != 0)
		return (NULL);
	ptr = dest;
	ptrsrc = src;
	while (n--)
		*ptr++ = (unsigned char)*ptrsrc++;
	return (dest);
}
