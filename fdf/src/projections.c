/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:45 by nass              #+#    #+#             */
/*   Updated: 2025/02/11 13:25:46 by nass             ###   ########.fr       */
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
