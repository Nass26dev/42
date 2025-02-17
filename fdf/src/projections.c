/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:45 by nass              #+#    #+#             */
/*   Updated: 2025/02/17 02:59:15 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	iso_proj(int x, int y, int z, t_param *param)
{
	t_point	projections;

	projections.x = (int)(param->zoom_factor * (COS30 * (x - y)));
	projections.y = (int)((param->zoom_factor * (SIN30 * (x + y) - (0.2 * z))));
	projections.x = (WIDTH / 2) - projections.x;
	projections.y += (HEIGHT / 2);
	projections.x += param->offset_x;
	projections.y += param->offset_y;
	return (projections);
}
