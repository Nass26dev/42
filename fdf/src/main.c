/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:20:50 by nass              #+#    #+#             */
/*   Updated: 2025/01/26 21:53:06 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(void *param)
{
	t_param *p;

	p = (t_param *)param;
	free_function(0, 1, 0, p->lst);
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, void *param)
{
	// t_param	*p;

	// p = (t_param *)param;
	if (keycode == 65307)
		close_window(param);
	return (0);
}

void	image_pixel_put(char *data, int x, int y, int color, int bpp, int sl)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		char	*pixel;

		pixel = data + (y * sl + x * (bpp / 8));

		*(unsigned int *)pixel = color;
	}
}

int	main(int argc, char **argv)
{
	t_param p;

	if (argc != 2)
	{
		write(1, "invalid format\n", 15);
		exit(EXIT_SUCCESS);
	}
	parse_file(argv[1], &p);
	p.zoom_factor = 32;
	p.offset_x = -100;
	p.offset_x = -200;
	p.proj = 0;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, TITLE);
	p.img = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.data = mlx_get_data_addr(p.img, &p.bpp, &p.sl, &p.endian);
	// render(&p);
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_hook(p.win, 17, 0, close_window, (void *)&p);
	mlx_key_hook(p.win, key_hook, (void *)&p);
	mlx_loop(p.mlx);
	return (0);
}
