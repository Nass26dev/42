/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:02:35 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/07 11:20:43 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dda(t_data *data, t_dda *dda, t_raycast *rc)
{
	if (rc->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (data->player_x - rc->map_x) * rc->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (rc->map_x + 1.0 - data->player_x) * rc->delta_x;
	}
	if (rc->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (data->player_y - rc->map_y) * rc->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (rc->map_y + 1.0 - data->player_y) * rc->delta_y;
	}
	dda->hit = 0;
}

static void	dda_wall_calc(t_raycast *rc, t_data *data, t_dda *dda)
{
	if (dda->side == 0)
		dda->wall_dist = (rc->map_x - data->player_x + (1 - dda->step_x) / 2)
			/ rc->ray_dir_x;
	else
		dda->wall_dist = (rc->map_y - data->player_y + (1 - dda->step_y) / 2)
			/ rc->ray_dir_y;
}

void	dda(t_data *data, t_raycast *rc, int x)
{
	t_dda	dda;

	init_dda(data, &dda, rc);
	while (dda.hit == 0)
	{
		if (dda.side_dist_x < dda.side_dist_y)
		{
			dda.side_dist_x += rc->delta_x;
			rc->map_x += dda.step_x;
			dda.side = 0;
		}
		else
		{
			dda.side_dist_y += rc->delta_y;
			rc->map_y += dda.step_y;
			dda.side = 1;
		}
		if (data->map[rc->map_y][rc->map_x] == '1')
			dda.hit = 1;
	}
	dda_wall_calc(rc, data, &dda);
	print_line(data, &dda, rc, x);
}

void	raycast(t_data *data)
{
	int			x;
	t_raycast	rc;

	x = 0;
	while (x < data->width)
	{
		rc.camera_x = 2 * x / (double)data->width - 1;
		rc.ray_dir_x = data->dir_x + data->plane_x * rc.camera_x;
		rc.ray_dir_y = data->dir_y + data->plane_y * rc.camera_x;
		rc.map_x = (int)data->player_x;
		rc.map_y = (int)data->player_y;
		rc.delta_x = fabs(1 / rc.ray_dir_x);
		rc.delta_y = fabs(1 / rc.ray_dir_y);
		dda(data, &rc, x);
		x++;
	}
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img_ptr)
		return (1);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->ll,
			&data->endian);
	if (!data->addr)
		return (1);
	data->bpp /= 8;
	print_c_f(data, 0, 0);
	raycast(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
