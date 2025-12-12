/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:00:57 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/14 10:06:42 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		size;

	if (!s || start >= ft_strlen(s))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (len > (ft_strlen(s) - start))
		size = (ft_strlen(s) - start);
	else
		size = len;
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = s[start++];
	str[i] = 0;
	return (str);
}
