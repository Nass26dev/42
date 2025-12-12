/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:18:04 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/15 11:52:31 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data->mlx_ptr)
		return (1);
	free_img(data, data->mlx_ptr);
	free_map(data->map);
	free_map(data->textures);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->dbt);
	free(data->mlx_ptr);
	if (data->fd != -1)
		close(data->fd);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC_PRESS)
		close_window(data);
	else if (keycode == W_PRESS)
		manage_w(data);
	else if (keycode == S_PRESS)
		manage_s(data);
	else if (keycode == A_PRESS)
		manage_a(data);
	else if (keycode == D_PRESS)
		manage_d(data);
	else if (keycode == RIGHT_ARROW_PRESS)
		manage_ra(data);
	else if (keycode == LEFT_ARROW_PRESS)
		manage_la(data);
	return (0);
}

int	parsing_helper(t_data *data, char **argv)
{
	if (get_texture(data, 0, NULL))
	{
		ft_putendl_fd("Error\nFailed to load texture(s)", 2);
		close_window(data);
		return (1);
	}
	if (manage_map(data, argv))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(data->error_msg, 2);
		free(data->error_msg);
		close_window(data);
		return (1);
	}
	return (0);
}

int	parsing(t_data *data, char **argv)
{
	if (is_cub(argv))
	{
		ft_putendl_fd("Error\nMap file argument is not valid", 2);
		close_window(data);
		return (1);
	}
	if (check_args(data, argv) || !data->textures)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(data->error_msg, 2);
		free(data->error_msg);
		close_window(data);
		return (1);
	}
	return (parsing_helper(data, argv));
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
	{
		ft_putendl_fd("Error\nUsage: ./cub3D <map_file>", 2);
		return (1);
	}
	if (MOVE_SPEED != 0.1 || ROT_SPEED != 0.05
		|| PLAYER_RADIUS != 0.1)
		return (1);
	if (init_mlx(&data))
		return (1);
	if (parsing(&data, argv))
		return (1);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, (void *)&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_hook, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
