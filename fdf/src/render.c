/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:04:12 by nass              #+#    #+#             */
/*   Updated: 2024/12/29 19:50:16 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_gradient_line(t_param *param, t_point one, t_point two,
		int color_start, int color_end)
{
	t_bresenham	b;

	b.diff_x = abs(two.x - one.x);
	b.diff_y = abs(two.y - one.y);
	if (b.diff_x > b.diff_y)
		b.steps = b.diff_x;
	else
		b.steps = b.diff_y;
	b.x_inc = (float)(two.x - one.x) / b.steps;
	b.y_inc = (float)(two.y - one.y) / b.steps;
	b.x = one.x;
	b.y = one.y;
	b.i = -1;
	while (++b.i <= b.steps)
	{
		b.t = (float)b.i / b.steps;
		b.color = insert_color(color_start, color_end, b.t);
		mlx_pixel_put(param->mlx, param->win, (int)(b.x), (int)(b.y), b.color);
		b.x += b.x_inc;
		b.y += b.y_inc;
	}
}

void	front_face(t_render *render, t_param *param)
{
	render->color = get_color(render->current_down->z);
	render->proj = choose_proj(render->current->x, render->current_down->y,
			render->current_down->z, param);
	mlx_pixel_put(param->mlx, param->win, render->proj.x + param->offset_x,
		render->proj.y + param->offset_y, render->color);
	if (render->current_down->next)
	{
		render->next_down = render->current_down->next;
		render->color = get_color(render->current_down->z);
		render->color2 = get_color(render->next_down->z);
		render->next_proj = choose_proj(render->current->x,
				render->next_down->y, render->next_down->z, param);
		render->one.x = render->proj.x + param->offset_x;
		render->one.y = render->proj.y + param->offset_y;
		render->two.x = render->next_proj.x + param->offset_x;
		render->two.y = render->next_proj.y + param->offset_y;
		draw_gradient_line(param, render->one, render->two, render->color,
			render->color2);
	}
}

void	back_face(t_render *render, t_param *param)
{
	render->next = render->current->next;
	if (render->next->down)
	{
		render->next_down = render->next->down;
		while (render->next_down
			&& render->next_down->y < render->current_down->y)
			render->next_down = render->next_down->next;
		if (render->next_down
			&& render->next_down->y == render->current_down->y)
		{
			render->color = get_color(render->current_down->z);
			render->color2 = get_color(render->next_down->z);
			render->next_proj = choose_proj(render->next->x,
					render->next_down->y, render->next_down->z, param);
			render->one.x = render->proj.x + param->offset_x;
			render->one.y = render->proj.y + param->offset_y;
			render->two.x = render->next_proj.x + param->offset_x;
			render->two.y = render->next_proj.y + param->offset_y;
			draw_gradient_line(param, render->one, render->two, render->color,
				render->color2);
		}
	}
}

void	render_3d(t_param *param)
{
	t_render	render;

	render.current = param->lst;
	while (render.current)
	{
		render.current_down = render.current->down;
		while (render.current_down)
		{
			front_face(&render, param);
			if (render.current->next)
				back_face(&render, param);
			render.current_down = render.current_down->next;
		}
		render.current = render.current->next;
	}
}
