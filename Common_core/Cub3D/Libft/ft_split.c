/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:38:56 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/24 18:26:00 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static char	**ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int	ft_word(char const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (*s == 0)
		return (0);
	if (c == 0)
		return (1);
	while (i < (int)ft_strlen(s))
	{
		if (s[i] != c && i == 0)
			word++;
		if (s[i] != c && s[i + 1] == '\0')
			word++;
		while (s[i] == c && s[i])
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				word++;
			i++;
		}
		while (s[i] != c && i < (int)ft_strlen(s))
			i++;
	}
	return (word);
}

static char	*ft_create(char **split, char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
	{
		ft_free(split);
		return (NULL);
	}
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	y;
	int		index;

	i = 0;
	y = 0;
	index = -1;
	split = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!s || !split)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[y++] = ft_create(split, s, index, i);
			index = -1;
		}
		i++;
	}
	split[y] = NULL;
	return (split);
}

// int	main(void)
// {
// 	char *str = "hello!";
// 	char cut = ' ';
// 	char **split = ft_split(str, cut);
// 	int	i;

// 	i = 0;
// 	if (!split)
// 		return(0);
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }
