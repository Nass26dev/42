/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:03:35 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/10 12:24:58 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	first_char(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] == 9 || str[i] == 32) && str[i])
		i++;
	return (str[i]);
}

char	last_char(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (str[i] == 9 || str[i] == 32 || str[i] == '\n')
		i--;
	return (str[i]);
}

static t_point	get_point(int fd, char **text, size_t i)
{
	char	*line;
	t_point	point;

	point.x = 0;
	point.y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (point.y == 0 && first_char(line) == '1')
			point.x = ft_strlen(line) - 1;
		if (first_char(line) != '\0')
			point.y++;
		free(line);
	}
	while (text[i])
		i++;
	point.text_tab_len = i;
	return (point);
}

char	**get_map(int fd, t_point point)
{
	char	**map;

	map = malloc(sizeof(char *) * (point.y + 1));
	if (!map)
		return (NULL);
	ft_memset(map, 0, sizeof(map));
	if (point.y <= 0)
	{
		free(map);
		return (NULL);
	}
	map = get_map_helper(fd, point, map);
	return (map);
}

char	**parse_file(const char *filename, t_data *data)
{
	t_point	point;
	char	**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		close(data->fd);
		return (NULL);
	}
	point = get_point(fd, data->textures, 0);
	data->point = point;
	data->map_height = point.y;
	data->map_width = point.x;
	close(fd);
	map = get_map(data->fd, point);
	close(data->fd);
	data->fd = -1;
	return (map);
}
