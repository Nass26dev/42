/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:20 by nass              #+#    #+#             */
/*   Updated: 2025/02/10 14:30:57 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	char *dst;
	
	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
	{
		dst = p->data + (y * p->sl+ x * (p->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	render(t_param *p)
{
	t_render r;
	t_point point;
	r.current = p->lst;
	while (r.current)
	{
		r.current_down = r.current->down;
		while (r.current_down)
		{
			point = iso_proj(r.current->x, r.current_down->y, r.current_down->z, p);
			my_mlx_pixel_put(p, point.x, point.y, 0xFFFFFF);\
			r.current_down = r.current_down->next;
		}
		r.current = r.current->next;
	}
}
