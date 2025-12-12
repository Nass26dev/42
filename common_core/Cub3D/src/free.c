/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:14:56 by tmarion           #+#    #+#             */
/*   Updated: 2025/11/12 11:40:52 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (!*map)
	{
		free(map);
		return ;
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	error_parse_cleanup(t_data *data)
{
	free_map(data->map);
	data->map = NULL;
	free_map(data->textures);
	data->textures = NULL;
	return (0);
}

void	free_img(t_data *data, void *mlx)
{
	int	i;

	i = 0;
	if (!data->dbt)
		return ;
	while (i < 4)
	{
		if (data->dbt[i].init == 0)
			return ;
		if (data->dbt[i].init == 1)
			mlx_destroy_image(mlx, data->dbt[i].img);
		i++;
	}
	return ;
}
