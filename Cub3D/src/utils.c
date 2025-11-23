/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:17:43 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/17 14:04:45 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_alloc_copy(const char *src)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	get_size_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

int	check_access(char *path, t_data *data, int index)
{
	int	fd;

	if (!path)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		data->text_index = index;
		data->text_bool = 1;
		return (1);
	}
	data->text_index = index;
	close(fd);
	return (0);
}

int	check_fd(char *path, char **text_file, int i)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (i == 1)
			free(text_file);
		return (-1);
	}
	return (fd);
}

int	parse_first_line(char **map)
{
	int	j;
	int	i;

	j = 0;
	if (!map[0])
		return (1);
	i = is_empty(map[0]);
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != 32
			&& map[i][j] != 9 && map[i][j] != 10)
		{
			return (1);
		}
		if (map[i][j] == '0')
			return (1);
		j++;
	}
	return (0);
}
