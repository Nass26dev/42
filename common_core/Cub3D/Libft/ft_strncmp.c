/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:40:21 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/24 13:40:21 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t nb)
{
	unsigned int	i;
	unsigned int	j;

	j = nb;
	i = 0;
	if (nb == 0)
		return (0);
	if (*s1 == 0)
		return ((unsigned char)s2[i] * (-1));
	if (*s2 == 0)
		return ((unsigned char)s1[i]);
	while (i <= j - 1 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*int	ft_strncmp(char *s1, char *s2, size_t nb)
{
	unsigned int	i;

	i = 0;
	nb--;
	while (i <= nb && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}*/
