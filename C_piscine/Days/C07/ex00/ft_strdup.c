/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:05:03 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/26 18:23:54 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = malloc(((ft_strlen(src) + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
/*
int main(int argc, char **argv)
{
	char	*str;
	argc = 2;
	str = ft_strdup(argv[1]);
	printf("%s", str);
}*/
