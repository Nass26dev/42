/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:39:45 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/23 17:07:04 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int	i;

	str = malloc(((ft_strlen(src) + 1) * sizeof(char)));
	if (!str)
		return (NULL);

	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
	return (str);
}

