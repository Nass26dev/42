/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:34:06 by nass              #+#    #+#             */
/*   Updated: 2025/02/10 09:49:23 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 1800
# endif

# ifndef HEIGHT
#  define HEIGHT 1200
# endif

# ifndef TITLE
#  define TITLE "Fdf"
# endif

# ifndef COS30
#  define COS30 0.866
# endif

# ifndef SIN30
#  define SIN30 0.5
# endif

# ifndef COLOR1
#  define COLOR1 0xFFFFFF
# endif

# ifndef COLOR2
#  define COLOR2 0xFF0000
# endif

typedef struct s_down
{
	int				y;
	int				z;
	struct s_down	*next;
}		t_down;

typedef struct s_map
{
	int				x;
	t_down			*down;
	struct s_map	*next;
}		t_map;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
	int		zoom_factor;
	int		offset_x;
	int		offset_y;
	int		proj;
	t_map	*lst;
}		t_param;

typedef struct s_free
{
	void	*ptr;
	t_map	*map;
	char	**split;
}		t_free;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_bresenham
{
	int				diff_x;
	int				diff_y;
	int				steps;
	float			x_inc;
	float			y_inc;
	int			t;
	int		x;
	int		y;
	int				i;
	int				color;
}					t_bresenham;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_render
{
	t_point	proj;
	t_point	next_proj;
	t_point	first;
	t_point	second;
	t_map	*current;
	t_map	*next;
	t_down	*current_down;
	t_down	*next_down;
	int		color;
	int		color2;
}					t_render;

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void    	free_function(int nf, int nfl, int nfs, ...);
void		parse_file(char *filename, t_param *m);
t_point		iso_proj(int x, int y, int z, t_param *param);
t_point		choose_proj(int x, int y, int z, t_param *param);
void		image_pixel_put(char *data, int x, int y, int color, int bpp, int sl);
void		my_mlx_pixel_put(t_param *p, int x, int y, int color);
void	render(t_param *p);

#endif