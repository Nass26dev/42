/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:58:18 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/28 10:58:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i + 1], charset) == 1
			&& ft_is_sep(str[i], charset) == 0)
			word++;
		i++;
	}
	return (word);
}

int	ft_find_word(char *str, char *charset)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

char	*allocate_cpy(char *str, char *sep)
{
	char	*new;
	int		i;
	int		j;

	new = malloc((ft_find_word(str, sep) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (sep[j])
		{
			if (str[i] == sep[j])
			{
				new[i] = 0;
				return (new);
			}
			j++;
		}
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_split(char *str, char *charset)
{
	char	**new;
	int		nb;
	int		j;

	j = 0;
	nb = ft_count_words(str, charset);
	new = malloc(((ft_count_words(str, charset) + 1) * sizeof(char *)));
	if (!new)
		return (NULL);
	while (j < nb)
	{
		while (ft_is_sep(*str, charset) == 1)
			str++;
		new[j] = allocate_cpy(str, charset);
		while (ft_is_sep(*str, charset) == 0)
			str++;
		j++;
	}
	new[j] = 0;
	return (new);
}
/*
int main(int argc, char **argv)
{
	int	i = 0;
	char	**test;
	(void)argc;
	test = ft_split(argv[1], argv[2]);
	while (test[i] != NULL)
	{
		printf("%s\n", test[i]);
		i++;
	}
}*/
