/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:22:34 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/23 17:06:45 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = dest;
	psrc = src;
	if (pdest != psrc)
	{
		if (psrc > pdest)
		{
			while (n--)
				*pdest++ = *psrc++;
		}
		else
		{
			while (n--)
				pdest[n] = psrc[n];
		}
	}
	return (dest);
}
