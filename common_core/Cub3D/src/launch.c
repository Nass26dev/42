/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:52:36 by nass              #+#    #+#             */
/*   Updated: 2025/11/17 14:21:29 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_error(t_data *data, int i)
{
	if (i >= 2)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (i >= 3)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (i >= 1)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	return (1);
}

int	is_cub(char **arg)
{
	int	i;
	int	fd;

	fd = open(arg[1], O_RDONLY);
	if (fd < 0)
		return (1);
	else
		close(fd);
	i = 0;
	while (arg[1][i])
		i++;
	if (i < 4)
		return (1);
	i -= 4;
	if (ft_strncmp(arg[1] + i, ".cub", 4) == 0 && ft_strlen(arg[1] + i) == 4)
		return (0);
	else
		return (1);
}

bool	check_args(t_data *data, char **argv)
{
	data->textures = fetch_textures_file(argv[1], 0, 0, data);
	if (!data->textures)
	{
		data->error_msg = ft_strdup("Failed to fetch textures");
		return (1);
	}
	if (is_text_paths(data->textures))
	{
		data->error_msg = ft_strdup("Invalid texture(s) path(s)");
		return (error_handler(data));
	}
	if (is_ceiling_color(data->textures) || is_floor_color(data->textures))
	{
		data->error_msg = ft_strdup("Missing valid color arg(s)");
		return (error_handler(data));
	}
	return (0);
}

bool	manage_map(t_data *data, char **argv)
{
	data->map = parse_file(argv[1], data);
	if (!data->map)
		return (1);
	if (parse_error(data))
		return (1);
	get_player_position(data);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->view_offset = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (mlx_error(data, 0));
	data->height = 720;
	data->width = 1280;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"Cub3D");
	if (!data->win_ptr)
		return (mlx_error(data, 1));
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img_ptr)
		return (mlx_error(data, 2));
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->ll,
			&data->endian);
	if (!data->addr)
		return (mlx_error(data, 3));
	data->bpp /= 8;
	data->pr_minimap = 0;
	return (0);
}
