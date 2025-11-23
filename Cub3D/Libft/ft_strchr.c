/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:24:14 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/27 00:24:14 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *find, int tofind)
{
	size_t	i;

	i = 0;
	tofind = (unsigned char)tofind;
	if (tofind > 127)
		return ((char *)find);
	while (i <= ft_strlen(find))
	{
		if (find[i] == tofind)
			return ((char *)find + i);
		i++;
	}
	return (NULL);
}
