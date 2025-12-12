/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:04:11 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/17 14:00:21 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parse_rgb(char *str)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 0;
	if (check_rgb_args(str))
		return (1);
	while (ft_isdigit(str[i]) == 0)
		i++;
	r = ft_atoi(str + i);
	while (str[i] != ',')
		i++;
	i++;
	g = ft_atoi(str + i);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	b = ft_atoi(str + i);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (1);
	return (0);
}

static int	parse_color_args(char **text, int i, int j)
{
	size_t	comma;

	comma = 0;
	while (text[i])
	{
		if (text[i][j] == 'F' || text[i][j] == 'C')
		{
			while (text[i][j] != '\n' && text[i][j])
			{
				j++;
				if (text[i][j] == ',')
					comma++;
			}
			if (comma == 2)
				comma = parse_rgb(text[i]);
			else
				return (1);
			if (comma == 1)
				return (1);
			j = 0;
			comma = 0;
		}
		i++;
	}
	return (0);
}

static int	parse_map_vertical(char **map, size_t i, size_t j)
{
	while (map[i])
	{
		while (map[i][j] && (map[i][j] == 32 || map[i][j] == 9))
			j++;
		if (map[i][j] == 10)
			break ;
		if (map[i][j] != '1')
			return (1);
		i = 0;
		j++;
	}
	j = 0;
	i = get_size_tab(map);
	while (map[i])
	{
		while (map[i][j] && (map[i][j] == 32 || map[i][j] == 9))
			i--;
		if (map[i][j] == 0 || map[i][j] == '\n')
			return (0);
		if (map[i][j] != '1')
			return (1);
		i = get_size_tab(map);
		j++;
	}
	return (0);
}

int	parse_helper(t_data *data)
{
	if (parse_color_args(data->textures, 0, 0))
	{
		data->error_msg = ft_strdup("Wrong RGB argument(s)");
		return (1);
	}
	if (parse_first_line(data->map))
	{
		data->error_msg = ft_strdup("Map is not valid");
		return (1);
	}
	if (is_valid_map(data->map) || parse_map_vertical(data->map, 0, 0))
	{
		data->error_msg = ft_strdup("Map is not valid");
		return (1);
	}
	return (0);
}

int	parse_error(t_data *data)
{
	if (!data->map)
		return (1);
	if (is_map(data->map))
	{
		data->error_msg = ft_strdup("Map is missing");
		return (1);
	}
	if (is_player(data->map))
	{
		data->error_msg = ft_strdup("Missing player in the map");
		return (1);
	}
	if (is_valid_player(data->map))
	{
		data->error_msg = ft_strdup("Invalid player in the map");
		return (1);
	}
	return (parse_helper(data));
}
