/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:04:45 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/20 15:04:45 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *find, int tofind, size_t size)
{
	unsigned int	i;
	char			*cast;

	tofind = (char)tofind;
	if (size == 0)
		return (NULL);
	size--;
	cast = (char *)find;
	i = 0;
	while (i <= size)
	{
		if (cast[i] == tofind)
			return ((char *)find + i);
		i++;
	}
	return (NULL);
}
