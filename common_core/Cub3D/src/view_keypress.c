/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:03:55 by nass              #+#    #+#             */
/*   Updated: 2025/11/10 12:33:46 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	manage_ra(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
	data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-ROT_SPEED) - data->plane_y
		* sin(-ROT_SPEED);
	data->plane_y = old_plane_x * sin(-ROT_SPEED) + data->plane_y
		* cos(-ROT_SPEED);
}

void	manage_la(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
	data->dir_y = old_dir_x * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(ROT_SPEED) - data->plane_y
		* sin(ROT_SPEED);
	data->plane_y = old_plane_x * sin(ROT_SPEED) + data->plane_y
		* cos(-ROT_SPEED);
}

void	print_pix(t_render *rnd, t_data *data, int y, int x)
{
	rnd->dst = rnd->adr + (y * data->ll + x * data->bpp);
	*(unsigned int *)rnd->dst = rnd->color;
}
