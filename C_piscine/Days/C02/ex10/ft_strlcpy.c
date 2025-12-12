/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:56:06 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/29 17:16:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int main(void)
{
	char dest1[100] = "Hello";
	char dest2[100] = "Hello";
	printf("%d\n", ft_strlcpy(dest1, "salut", 5));
	printf("%s\n", dest1);
	printf("%zu\n", strlcpy(dest2, "salut", 5));
	printf("%s\n", dest2);
}
*/
