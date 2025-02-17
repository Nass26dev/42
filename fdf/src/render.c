/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:20 by nass              #+#    #+#             */
/*   Updated: 2025/02/17 17:24:02 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void fill_by_black(t_param *p)
{
	int i;
	int j;

	i = 0;
	while (i <= HEIGHT)
	{
		j = 0;
		while (j <= WIDTH)
		{
			my_mlx_pixel_put(p, j, i, BLACK);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	char *dst;
	
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = p->data + (y * p->sl+ x * (p->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void draw_line(t_param *p, t_point p1, t_point p2, int color)
{
	t_bresenham b;

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
	{
		my_mlx_pixel_put(p, p1.x, p1.y, color);
		b.err2 = 2 * b.err;
		if (b.err2 > -b.abs_dsty)
		{
			b.err -= b.abs_dsty;
			p1.x += b.dir_x;
		}
		if (b.err2 < b.abs_dstx)
		{
			b.err += b.abs_dstx;
			p1.y += b.dir_y;
		}
	}
}

void horizontal_path(t_render *r, t_param *p)
{
	r->point1 = iso_proj(r->current->x, r->current_down->y, r->current_down->z, p);
	r->color = r->current_down->color;
	if (r->current_down->next)
	{
		r->point2 = iso_proj(r->current->x, r->current_down->next->y, r->current_down->next->z, p);
		draw_line(p, r->point1, r->point2, r->color);
	}
	if (r->current->next)
	{
		r->next_down = r->current->next->down;
		while (r->next_down && r->next_down->y != r->current_down->y)
		r->next_down = r->next_down->next;
		if (r->next_down)
		{
			r->point2 = iso_proj(r->current->next->x, r->next_down->y, r->next_down->z, p);
			draw_line(p, r->point1, r->point2, r->color);
		}
	}
}

void render(t_param *p)
{
	t_render r;
	
	r.current = p->lst;
	while (r.current)
	{
		r.current_down = r.current->down;
		while (r.current_down)
		{
			horizontal_path(&r, p);
			r.current_down = r.current_down->next;
		}
		r.current = r.current->next;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
