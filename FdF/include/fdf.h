/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:34:06 by nass              #+#    #+#             */
/*   Updated: 2025/02/19 14:51:27 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef WIDTH
#  define WIDTH 1800
# endif

# ifndef HEIGHT
#  define HEIGHT 1200
# endif

# ifndef COS30
#  define COS30 0.866
# endif

# ifndef SIN30
#  define SIN30 0.5
# endif

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef BLACK
#  define BLACK 0x000000
# endif

typedef struct s_down
{
	int				y;
	int				z;
	int				color;
	struct s_down	*next;
}					t_down;

typedef struct s_map
{
	int				x;
	t_down			*down;
	struct s_map	*next;
}					t_map;

typedef struct s_param
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;
	int				zoom_factor;
	int				offset_x;
	int				offset_y;
	t_map			*lst;
}					t_param;

typedef struct s_free
{
	void			*ptr;
	t_map			*map;
	char			**split;
}					t_free;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_bresenham
{
	int				abs_dstx;
	int				abs_dsty;
	int				dir_x;
	int				dir_y;
	int				err;
	int				err2;
}					t_bresenham;

typedef struct s_render
{
	t_map			*current;
	t_down			*current_down;
	t_down			*next_down;
	t_point			point1;
	t_point			point2;
	int				color;
}					t_render;

void				free_function(int nf, int nfl, int nfs, ...);
void				parse_file(char *filename, t_param *m);
t_point				iso_proj(int x, int y, int z, t_param *param);
void				my_mlx_pixel_put(t_param *p, int x, int y, int color);
void				render(t_param *p);
int					get_color(char *s_line);
void				fill_by_black(t_param *p);
void				draw_line(t_param *p, t_point p1, t_point p2, int color);

#endif