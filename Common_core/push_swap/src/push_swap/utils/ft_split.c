/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:55:20 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/22 02:52:05 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap/push_swap.h"

void	free_split(char **split, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(split[j++]);
	free(split);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			word++;
		i++;
	}
	return (word);
}

int	find_word(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*allocate_cpy(char *str, char sep)
{
	char	*new;
	int		i;

	new = malloc((find_word(str, sep) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (*str && *str != sep)
		new[i++] = *str++;
	new[i] = 0;
	return (new);
}

char	**ft_split(const char *s, char c)
{
	char	**new;
	int		nb;
	int		j;

	j = 0;
	nb = count_words(s, c);
	new = malloc(((nb + 1) * sizeof(char *)));
	if (!new)
		return (NULL);
	while (j < nb)
	{
		while (*s == c)
			s++;
		new[j] = allocate_cpy((char *)s, c);
		if (!new[j])
		{
			free_split(new, j);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		j++;
	}
	new[j] = NULL;
	return (new);
}
