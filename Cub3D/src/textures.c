/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:27:45 by tmarion           #+#    #+#             */
/*   Updated: 2025/11/10 12:28:09 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_size_text_file(const char *path, int count)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		if (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0)
			count++;
		if (count == 2)
			break ;
		free(line);
	}
	free(line);
	line = NULL;
	if (fd >= 0)
		close(fd);
	return (i + 8);
}

char	**fetch_textures_file(const char *path, int count, int i, t_data *data)
{
	char	**textures_file;
	char	*line;

	textures_file = malloc(sizeof(char *) * get_size_text_file(path, 0) + 8);
	if (!textures_file)
		return (NULL);
	data->fd = open(path, O_RDONLY);
	if (data->fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		textures_file[i] = line;
		i++;
		if (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0)
			count++;
		if (count == 2)
			break ;
	}
	textures_file[i] = NULL;
	return (textures_file);
}

static char	*fetch_texture_path(t_data *data, const char *texture_id)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->textures[i])
	{
		if (ft_strncmp(texture_id, data->textures[i], 2) == 0)
		{
			while (data->textures[i][j] != '.' && data->textures[i][j])
				j++;
			return (ft_alloc_copy(data->textures[i] + j));
		}
		i++;
	}
	return (NULL);
}

static char	*wich_path(t_data *data, size_t i)
{
	char	*path;

	path = NULL;
	if (i == 0)
		path = fetch_texture_path(data, "SO");
	if (i == 1)
		path = fetch_texture_path(data, "WE");
	if (i == 2)
		path = fetch_texture_path(data, "NO");
	if (i == 3)
		path = fetch_texture_path(data, "EA");
	if (!path)
		return (NULL);
	path[ft_strlen(path) - 1] = 0;
	return (path);
}

int	get_texture(t_data *data, size_t i, char *path)
{
	data->dbt = malloc(sizeof(t_dbt) * 4);
	if (!data->dbt)
		return (1);
	init_dbt(data->dbt);
	while (i < 4)
	{
		path = wich_path(data, i);
		if (check_access(path, data, i))
			return (1);
		data->dbt[i].img = mlx_xpm_file_to_image(data->mlx_ptr, path,
				&data->dbt[i].width, &data->dbt[i].height);
		free(path);
		if (!data->dbt[i].img)
			return (1);
		data->dbt[i].init = 1;
		data->dbt[i].addr = mlx_get_data_addr(data->dbt[i].img, &data->dbt->bpp,
				&data->dbt->line_len, &data->dbt->endian);
		if (!data->dbt[i].addr)
			return (1);
		i++;
	}
	return (0);
}
