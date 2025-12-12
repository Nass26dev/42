/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:22 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/14 14:27:25 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_sepa(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	start_index(char *s1, char *set)
{
	int	i;

	i = 0;
	while (char_is_sepa(s1[i], set))
		i++;
	return (i);
}

int	end_index(char *s1, char *set)
{
	int	i;

	i = (ft_strlen(s1) - 1);
	while (i >= 0 && char_is_sepa(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*str;
	size_t		i;

	i = 0;
	start = start_index((char *)s1, (char *)set);
	end = end_index((char *)s1, (char *)set);
	if (start == ft_strlen((char *)s1))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
