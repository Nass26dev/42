/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_here.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:13:11 by tmarion           #+#    #+#             */
/*   Updated: 2025/11/17 14:03:54 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_floor_color(char **text)
{
	size_t	i;

	i = 0;
	if (!text)
		return (1);
	while (text[i])
	{
		if (text[i][0] == 'F')
			return (0);
		i++;
	}
	return (1);
}

int	is_ceiling_color(char **text)
{
	size_t	i;

	i = 0;
	if (!text)
		return (1);
	while (text[i])
	{
		if (text[i][0] == 'C')
			return (0);
		i++;
	}
	return (1);
}

int	is_text_paths(char **text)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (text[i])
	{
		if (ft_strncmp(text[i], "NO", 2) == 0 && check_text_args(text[i] + 2))
			count++;
		if (ft_strncmp(text[i], "SO", 2) == 0 && check_text_args(text[i] + 2))
			count++;
		if (ft_strncmp(text[i], "WE", 2) == 0 && check_text_args(text[i] + 2))
			count++;
		if (ft_strncmp(text[i], "EA", 2) == 0 && check_text_args(text[i] + 2))
			count++;
		i++;
	}
	if (count != 4)
		return (1);
	return (0);
}

int	is_map(char **map)
{
	size_t	i;
	size_t	j;
	int		trigger;

	i = 0;
	trigger = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0')
				trigger = 1;
			j++;
		}
		i++;
	}
	if (i == 0 || trigger == 0)
		return (1);
	return (0);
}

int	is_player(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
