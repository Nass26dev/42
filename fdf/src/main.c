/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:20:50 by nass              #+#    #+#             */
/*   Updated: 2025/02/17 02:51:48 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(void *param)
{
	t_param *p;

	p = (t_param *)param;
	free_function(0, 1, 0, p->lst);
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, void *param)
{
	t_param	*p;

	p = (t_param *)param;
	if (keycode == 65307)
		close_window(param);
	else if (keycode == 61)
	{
		p->zoom_factor *= 2;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 45)
	{
		if (p->zoom_factor == 2)
			return (0);
		p->zoom_factor /= 2;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 65362)
	{
		p->offset_y -= 20;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 65361)
	{
		p->offset_x -= 20;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 65364)
	{
		p->offset_y += 20;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 65363)
	{
		p->offset_x += 20;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 38)
	{
		if (p->proj == 1)
			return (0);
		p->proj = 1;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 233)
	{
		if (p->proj == 2)
			return (0);
		p->proj = 2;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 34)
	{
		if (p->proj == 3)
			return (0);
		p->proj = 3;
		fill_by_black(p);
		render(p);
	}
	else if (keycode == 39)
	{
		if (p->proj == 4)
			return (0);
		p->proj = 4;
		fill_by_black(p);
		render(p);
	}
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

bool verif_file(char *file)
{
	int i;

	i = ft_strlen(file) - 1;
	if (file[i--] != 'f')
		return (false);
	if (file[i--] != 'd')
		return (false);
	if (file[i--] != 'f')
		return (false);
	if (file[i--] != '.')
		return (false);
	return (true);
}
int	main(int argc, char **argv)
{
	t_param p;

	if (argc != 2 || !verif_file(argv[1]))
	{
		write(1, "invalid format\n", 15);
		exit(EXIT_SUCCESS);
	}
	parse_file(argv[1], &p);
	p.zoom_factor = 32;
	p.offset_x = 0;
	p.offset_y = 0;
	p.proj = 1;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, TITLE);
	p.img = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.data = mlx_get_data_addr(p.img, &p.bpp, &p.sl, &p.endian);
	render(&p);
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_hook(p.win, 17, 0, close_window, (void *)&p);
	mlx_key_hook(p.win, key_hook, (void *)&p);
	mlx_loop(p.mlx);
	return (0);
}
