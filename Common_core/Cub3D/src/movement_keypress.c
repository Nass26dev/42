/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keypress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:56:23 by nass              #+#    #+#             */
/*   Updated: 2025/11/10 09:48:38 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	manage_w(t_data *data)
{
	double	new_x;
	double	new_y;

	normalize_dir(data);
	new_x = data->player_x + data->dir_x * MOVE_SPEED;
	new_y = data->player_y + data->dir_y * MOVE_SPEED;
	if (can_move(data, new_x, data->player_y))
		data->player_x = new_x;
	if (can_move(data, data->player_x, new_y))
		data->player_y = new_y;
}

void	manage_s(t_data *data)
{
	double	new_x;
	double	new_y;

	normalize_dir(data);
	new_x = data->player_x - data->dir_x * MOVE_SPEED;
	new_y = data->player_y - data->dir_y * MOVE_SPEED;
	if (can_move(data, new_x, data->player_y))
		data->player_x = new_x;
	if (can_move(data, data->player_x, new_y))
		data->player_y = new_y;
}

void	manage_a(t_data *data)
{
	double	new_x;
	double	new_y;

	normalize_dir(data);
	new_x = data->player_x - data->plane_x * MOVE_SPEED;
	new_y = data->player_y - data->plane_y * MOVE_SPEED;
	if (can_move(data, new_x, data->player_y))
		data->player_x = new_x;
	if (can_move(data, data->player_x, new_y))
		data->player_y = new_y;
}

void	manage_d(t_data *data)
{
	double	new_x;
	double	new_y;

	normalize_dir(data);
	new_x = data->player_x + data->plane_x * MOVE_SPEED;
	new_y = data->player_y + data->plane_y * MOVE_SPEED;
	if (can_move(data, new_x, data->player_y))
		data->player_x = new_x;
	if (can_move(data, data->player_x, new_y))
		data->player_y = new_y;
}
