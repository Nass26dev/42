/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:48:55 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/29 19:53:49 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(int keycode, void *param)
{
	t_param	*p;

	p = param;
	(void)keycode;
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_display(p->mlx);
	free_lst(p->lst);
	free(p->mlx);
	free(p);
	exit(0);
	return (0);
}

void	display_instructions(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 50, 70, 0xFF0000,"PRESS \"SPACE\" TO SHOW AND HIDE THE HELP WINDOW !");
	mlx_string_put(mlx, win, 50, 100, 0x0000FF, "By using keys \"1\",\"2\",\"3\", \"4\" you can juggle between the different projections!");
	mlx_string_put(mlx, win, 50, 130, 0xFFFFFF, "\"1\" = isometric projection");
	mlx_string_put(mlx, win, 50, 160, 0xFFFFFF, "\"2\" = 2d projection");
	mlx_string_put(mlx, win, 50, 190, 0xFFFFFF, "\"3\" = oblic projection");
	mlx_string_put(mlx, win, 50, 220, 0xFFFFFF,"\"4\" = axonometric projection");
	mlx_string_put(mlx, win, 50, 250, 0x0000FF,"you can also zoom in and out !");
	mlx_string_put(mlx, win, 50, 280, 0xFFFFFF, "\"+\" = zoom in");
	mlx_string_put(mlx, win, 50, 310, 0xFFFFFF, "\"-\" = zoom out");
	mlx_string_put(mlx, win, 50, 340, 0x0000FF,"the directional arrows will allow you to move the camera !");
	mlx_string_put(mlx, win, 50, 370, 0xFFFFFF,"top = move the camera upwards");
	mlx_string_put(mlx, win, 50, 400, 0xFFFFFF,"bottom = move the camera down");
	mlx_string_put(mlx, win, 50, 430, 0xFFFFFF,"left = move the camera to the left");
	mlx_string_put(mlx, win, 50, 460, 0xFFFFFF,"right = move the camera to the right");
}

int	key_hook(int keycode, void *param)
{
	t_param		*p;
	static int	last;

	p = param;
	if (keycode == ESC)
		close_window(keycode, param);
	if (keycode == ZOOM_IN)
	{
		if (p->proj == 0)
			return (0);
		if (p->zoom_factor == 128)
			return (0);
		p->zoom_factor *= 2;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == ZOOM_OUT)
	{
		if (p->proj == 0)
			return (0);
		if (p->zoom_factor == 1)
			return (0);
		p->zoom_factor /= 2;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == RIGHT_ARROW)
	{
		if (p->proj == 0)
			return (0);
		p->offset_x -= 50;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == LEFT_ARROW)
	{
		if (p->proj == 0)
			return (0);
		p->offset_x += 50;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == DOWN_ARROW)
	{
		if (p->proj == 0)
			return (0);
		p->offset_y -= 50;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == UPPER_ARROW)
	{
		if (p->proj == 0)
			return (0);
		p->offset_y += 50;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == ONE)
	{
		if (p->proj == 1)
			return (0);
		p->zoom_factor = 32;
		p->offset_x = -100;
		p->offset_y = -200;
		p->proj = 1;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == TWO)
	{
		if (p->proj == 2)
			return (0);
		p->proj = 2;
		p->zoom_factor = 32;
		p->offset_x = -250;
		p->offset_y = -200;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == THREE)
	{
		if (p->proj == 3)
			return (0);
		p->proj = 3;
		p->zoom_factor = 32;
		p->offset_x = -250;
		p->offset_y = -200;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == FOUR)
	{
		if (p->proj == 4)
			return (0);
		p->proj = 4;
		p->zoom_factor = 32;
		p->offset_x = -250;
		p->offset_y = -200;
		mlx_clear_window(p->mlx, p->win);
		render_3d(p);
	}
	if (keycode == SPACE)
	{
		if (p->proj == 0)
		{
			if (last == 0)
				last = 1;
			p->proj = last;
			mlx_clear_window(p->mlx, p->win);
			render_3d(p);
			return (0);
		}
		last = p->proj;
		p->proj = 0;
		mlx_clear_window(p->mlx, p->win);
		display_instructions(p->mlx, p->win);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*param;
	int		fd;

	(void)argc;
	param = malloc(sizeof(t_param));
	if (!param)
		exit(0);
	param->zoom_factor = 32;
	param->offset_x = -100;
	param->offset_y = -200;
	param->proj = 0;
	param->degrees = 30;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, WIDTH, HEIGHT, "Fdf");
	fd = open(argv[1], O_RDONLY);
	param->lst = read_file(fd, param);
	close(fd);
	display_instructions(param->mlx, param->win);
	mlx_hook(param->win, 17, 0, close_window, NULL);
	mlx_key_hook(param->win, key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
