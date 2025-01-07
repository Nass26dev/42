/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:33:50 by nass              #+#    #+#             */
/*   Updated: 2024/12/29 19:50:12 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	two_dim_proj(int x, int y, int z, t_param *param)
{
	t_point	projections;

	(void)z;
	projections.x = (int)(param->zoom_factor * y);
	projections.y = (int)(param->zoom_factor * -x);
	projections.x = (WIDTH / 2) + projections.x;
	projections.y = (HEIGHT / 2) - projections.y;
	return (projections);
}

t_point	iso_proj(int x, int y, int z, t_param *param)
{
	t_point	projections;

	projections.x = (int)(param->zoom_factor * (COS30 * (x - y)));
	projections.y = (int)((param->zoom_factor * (SIN30 * (x + y) - (0.2 * z))));
	projections.x = (WIDTH / 2) - projections.x;
	projections.y += (HEIGHT / 2);
	return (projections);
}

t_point	oblic_proj(int x, int y, int z, t_param *param)
{
	t_point	projections;

	projections.x = (int)(param->zoom_factor * (y - 0.5 * z));
	projections.y = (int)(param->zoom_factor * (-x - 0.5 * z));
	projections.x = (WIDTH / 2) + projections.x;
	projections.y = (HEIGHT / 2) - projections.y;
	return (projections);
}

t_point	axonometric_proj(int x, int y, int z, t_param *param)
{
	t_point	projections;

	projections.x = (int)(param->zoom_factor * y / (1 + z * 0.01));
	projections.y = (int)(param->zoom_factor * -x / (1 + z * 0.01));
	projections.x = (WIDTH / 2) + projections.x;
	projections.y = (HEIGHT / 2) - projections.y;
	return (projections);
}

t_point	choose_proj(int x, int y, int z, t_param *param)
{
	t_point	projections;

	if (param->proj == 1)
		projections = iso_proj(x, y, z, param);
	else if (param->proj == 2)
		projections = two_dim_proj(x, y, z, param);
	else if (param->proj == 3)
		projections = oblic_proj(x, y, z, param);
	else
		projections = axonometric_proj(x, y, z, param);
	return (projections);
}
