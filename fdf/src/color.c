/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:43:02 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/29 19:49:55 by nyousfi          ###   ########.fr       */
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
