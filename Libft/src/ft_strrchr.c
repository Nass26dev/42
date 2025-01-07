/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:17 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/23 17:07:36 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	j = -2;
	i = -1;
	while (str[++i])
	{
		if (str[i] == (unsigned char)c)
			j = i;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(str + i));
	if (j == -2)
		return (NULL);
	return ((char *)(str + j));
}
