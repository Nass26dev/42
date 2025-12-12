/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:13:02 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/27 16:30:35 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_count(int size, char **strs)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size)
	{
		j += ft_strlen(strs[i]);
		i++;
	}
	return (j);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	i = 0;
	if (size == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(((ft_count(size, strs) + ((ft_strlen(sep) * size)) + 1)));
	if (!str)
		return (str);
	str[0] = '\0';
	while (1)
	{
		ft_strcat(str, strs[i]);
		size--;
		if (size == 0)
			return (str);
		if (strs[i + 1] != NULL)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	char	*sep = "/";
	argv++;
	printf("%s", ft_strjoin((argc - 1), argv, sep));
}*/
