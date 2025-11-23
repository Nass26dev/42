/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:06:51 by tmarion           #+#    #+#             */
/*   Updated: 2025/09/30 19:13:56 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	fetch_color(t_data *data, const char c)
{
	size_t	i;
	size_t	start;
	int		r;
	int		g;
	int		b;

	i = 0;
	start = 0;
	while (data->textures[i][start] != c)
		i++;
	while (data->textures[i][start] < '0' || data->textures[i][start] > '9')
		start++;
	r = ft_atoi(data->textures[i] + start);
	while (data->textures[i][start] != ',')
		start++;
	start++;
	g = ft_atoi(data->textures[i] + start);
	while (data->textures[i][start] != ',')
		start++;
	b = ft_atoi(data->textures[i] + start + 1);
	return ((r << 16) | (g << 8) | b);
}

static void	draw_ceiling(t_data *data, int c_color, int x, int y)
{
	unsigned int	color_check;
	char			*pix;

	color_check = 0x000000;
	while (x < data->width)
	{
		while (y < 360)
		{
			pix = data->addr + (y * data->ll + x * data->bpp);
			color_check = *(unsigned int *)pix;
			if (color_check == 0x000000)
				*(unsigned int *)pix = c_color;
			y++;
		}
		color_check = 0x000000;
		x++;
		y = 0;
	}
	return ;
}

static void	draw_floor(t_data *data, int f_color, int x, int y)
{
	unsigned int	color_check;
	char			*pix;

	color_check = 0x000000;
	while (x < data->width)
	{
		while (y > 360)
		{
			pix = data->addr + (y * data->ll + x * data->bpp);
			color_check = *(unsigned int *)pix;
			if (color_check == 0x000000)
				*(unsigned int *)pix = f_color;
			y--;
		}
		color_check = 0x000000;
		x++;
		y = data->height;
	}
	return ;
}

void	print_c_f(t_data *data, int x, int y)
{
	unsigned int	c_color;
	unsigned int	f_color;

	c_color = fetch_color(data, 'C');
	f_color = fetch_color(data, 'F');
	if (c_color == 1024 || f_color == 1024)
		return ;
	draw_ceiling(data, c_color, x, y);
	x = 0;
	y = data->height;
	draw_floor(data, f_color, x, y);
}
