/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keypress_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:48:41 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/17 14:04:55 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 10 && str[i] != 9 && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

void	normalize_dir(t_data *data)
{
	double	len;

	len = sqrt(data->dir_x * data->dir_x + data->dir_y * data->dir_y);
	if (len != 0.0)
	{
		data->dir_x /= len;
		data->dir_y /= len;
	}
}

int	can_move(t_data *data, double new_x, double new_y)
{
	if (data->map[(int)(new_y - PLAYER_RADIUS)][(int)(new_x
			- PLAYER_RADIUS)] == '1')
		return (0);
	if (data->map[(int)(new_y - PLAYER_RADIUS)][(int)(new_x
			+ PLAYER_RADIUS)] == '1')
		return (0);
	if (data->map[(int)(new_y + PLAYER_RADIUS)][(int)(new_x
			- PLAYER_RADIUS)] == '1')
		return (0);
	if (data->map[(int)(new_y + PLAYER_RADIUS)][(int)(new_x
			+ PLAYER_RADIUS)] == '1')
		return (0);
	return (1);
}

int	error_handler(t_data *data)
{
	free_map(data->textures);
	mlx_error(data, 3);
	close(data->fd);
	return (1);
}
