/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:45 by nass              #+#    #+#             */
/*   Updated: 2025/02/19 14:21:15 by nyousfi          ###   ########.fr       */
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

void	draw(t_param *p, t_bresenham *b, t_point *p1, int color)
{
	my_mlx_pixel_put(p, p1->x, p1->y, color);
	b->err2 = 2 * b->err;
	if (b->err2 > -b->abs_dsty)
	{
		b->err -= b->abs_dsty;
		p1->x += b->dir_x;
	}
	if (b->err2 < b->abs_dstx)
	{
		b->err += b->abs_dstx;
		p1->y += b->dir_y;
	}
}

void	draw_line(t_param *p, t_point p1, t_point p2, int color)
{
	t_bresenham	b;

	b.abs_dstx = abs(p2.x - p1.x);
	b.abs_dsty = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		b.dir_x = 1;
	else
		b.dir_x = -1;
	if (p1.y < p2.y)
		b.dir_y = 1;
	else
		b.dir_y = -1;
	b.err = b.abs_dstx - b.abs_dsty;
	while (p1.x != p2.x || p1.y != p2.y)
		draw(p, &b, &p1, color);
}
