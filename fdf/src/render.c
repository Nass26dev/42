/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:20 by nass              #+#    #+#             */
/*   Updated: 2025/02/16 21:01:27 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;

    while (p1.x != p2.x || p1.y != p2.y)
    {
        my_mlx_pixel_put(p, p1.x, p1.y, color);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            p1.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            p1.y += sy;
        }
    }
}

void render(t_param *p)
{
    t_map *current;
    t_down *current_down;
    t_point point1, point2;
    int color;
    
    current = p->lst;
    while (current) // Parcourt vertical (vers le bas)
    {
        current_down = current->down;
        while (current_down) // Parcourt horizontal (vers la droite)
        {
            // Projection du point actuel
            point1 = iso_proj(current->x, current_down->y, current_down->z, p);
            color = current_down->color;
            // Tracer la ligne vers la droite (horizontal)
            if (current_down->next)
            {
                point2 = iso_proj(current->x, current_down->next->y, current_down->next->z, p);
                draw_line(p, point1, point2, color);
            }

            // Tracer la ligne vers le bas (vertical)
            if (current->next)
            {
                t_down *next_down = current->next->down;
                
                // Aller au même niveau en y dans la colonne du bas
                while (next_down && next_down->y != current_down->y)
                    next_down = next_down->next;

                if (next_down) // Si un point correspondant est trouvé en bas
                {
                    point2 = iso_proj(current->next->x, next_down->y, next_down->z, p);
                    draw_line(p, point1, point2, color);
                }
            }
            current_down = current_down->next;
        }
        current = current->next; // Descendre
    }
    mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
