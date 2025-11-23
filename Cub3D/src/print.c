/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:59:53 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/06 16:39:33 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	remap_val(int value, t_render *rnd, int start2, int stop2)
{
	int	val_remap;

	if (rnd->start >= 0 && rnd->end <= 719)
	{
		val_remap = (float)(value - rnd->draw_start) / (rnd->draw_end
				- rnd->draw_start) * (stop2 - start2);
	}
	else
	{
		val_remap = (float)(value - rnd->start) / (rnd->end
				- rnd->start) * (stop2 - start2);
	}
	return (val_remap);
}

static void	init_render(t_render *rnd, t_data *data, t_dda *dda)
{
	ft_memset(rnd, 0, sizeof(*rnd));
	rnd->adr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->ll,
			&data->endian);
	data->bpp /= 8;
	rnd->line_height = (int)((float)(data->height / dda->wall_dist));
	rnd->draw_start = -rnd->line_height / 2 + data->height / 2;
	rnd->draw_end = rnd->line_height / 2 + data->height / 2;
	rnd->start = rnd->draw_start;
	rnd->end = rnd->draw_end;
	if (rnd->draw_start < 0)
		rnd->draw_start = 0;
	if (rnd->draw_end >= data->height)
		rnd->draw_end = data->height - 1;
	return ;
}

static void	draw_false_dda(t_render *rnd, t_data *data, t_raycast *rc)
{
	if (rc->ray_dir_x < 0)
		rnd->color = ((int *)data->dbt[3].addr)[rnd->texxpos
			% data->dbt[3].width
			+ rnd->texypos * data->dbt[3].width];
	else
		rnd->color = ((int *)data->dbt[1].addr)[rnd->texxpos
			% data->dbt[1].width
			+ rnd->texypos * data->dbt[1].width];
}

static void	draw_true_dda(t_render *rnd, t_data *data, t_raycast *rc)
{
	if (rc->ray_dir_y > 0)
		rnd->color = ((int *)data->dbt[2].addr)[rnd->texxpos
			% data->dbt[2].width
			+ rnd->texypos * data->dbt[2].width];
	else
		rnd->color = ((int *)data->dbt[0].addr)[rnd->texxpos
			% data->dbt[0].width
			+ rnd->texypos * data->dbt[0].width];
}

void	print_line(t_data *data, t_dda *dda, t_raycast *rc, int x)
{
	t_render	rnd;
	int			y;

	init_render(&rnd, data, dda);
	y = rnd.draw_start - 1;
	while (++y < rnd.draw_end)
	{
		if (dda->side == 0)
			rnd.wallx = data->player_y + dda->wall_dist * rc->ray_dir_y;
		else
			rnd.wallx = data->player_x + dda->wall_dist * rc->ray_dir_x;
		rnd.wallx = rnd.wallx - floor(rnd.wallx);
		rnd.texxpos = (int)(rnd.wallx * (double)data->dbt[0].width);
		if ((dda->side == 0 && rc->ray_dir_x > 0)
			|| (dda->side == 1 && rc->ray_dir_y < 0))
			rnd.texxpos = data->dbt[0].width - rnd.texxpos - 1;
		rnd.texypos = remap_val(y, &rnd, 0, data->dbt[0].height);
		if (dda->side == 0)
			draw_false_dda(&rnd, data, rc);
		else
			draw_true_dda(&rnd, data, rc);
		print_pix(&rnd, data, y, x);
	}
	print_pix(&rnd, data, y, x);
}
