/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:30:17 by nass              #+#    #+#             */
/*   Updated: 2025/01/25 14:36:58 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_color(int z)
{
	if (z <= 0)
		return (COLOR1);
	else
		return (COLOR2);
}

t_rgb	hex_to_rgb(int hex)
{
	t_rgb	rgb;

	rgb.r = (hex >> 16) & 0xFF;
	rgb.g = (hex >> 8) & 0xFF;
	rgb.b = hex & 0xFF;
	return (rgb);
}

int	insert_color(int color_start, int color_end, float t)
{
	t_rgb	start;
	t_rgb	end;
	t_rgb	rgb;

	start = hex_to_rgb(color_start);
	end = hex_to_rgb(color_end);
	rgb.r = (int)((1 - t) * start.r + t * end.r);
	rgb.g = (int)((1 - t) * start.g + t * end.g);
	rgb.b = (int)((1 - t) * start.b + t * end.b);
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}
