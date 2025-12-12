/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:18:02 by nyousfi           #+#    #+#             */
/*   Updated: 2025/11/17 14:05:09 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define PLAYER_RADIUS 0.1
# define W_PRESS 119
# define S_PRESS 115
# define A_PRESS 97
# define D_PRESS 100
# define ESC_PRESS 65307
# define RIGHT_ARROW_PRESS 65361
# define LEFT_ARROW_PRESS 65363
# define UP_ARROW_PRESS 65362
# define DOWN_ARROW_PRESS 65364
# define RED 0xFF0000
# define GRAY 0x777777
# define WHITE 0xFFFFFF

typedef struct s_dda
{
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				hit;
	int				side;
	double			wall_dist;
}					t_dda;

typedef struct s_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_x;
	double			delta_y;
	int				map_x;
	int				map_y;
}					t_raycast;

typedef struct s_dbt
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
	int				init;
}					t_dbt;

typedef struct s_point
{
	int				x;
	int				y;
	int				text_tab_len;
}					t_point;

typedef struct s_render
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	char			*adr;
	unsigned int	color;
	double			wallx;
	int				texypos;
	char			*dst;
	int				texxpos;
	int				start;
	int				end;
}					t_render;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*map_file;
	int				width;
	int				height;
	int				map_height;
	int				map_width;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			player_x;
	double			player_y;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	char			**map;
	int				view_offset;
	char			**textures;
	int				c_color;
	int				f_color;
	char			*error_msg;
	int				text_index;
	bool			text_bool;
	bool			pr_minimap;
	int				moved;
	int				fd;
	struct s_point	point;
	struct s_dbt	*dbt;
}					t_data;

// utils.c
char				*ft_alloc_copy(const char *src);
int					get_size_tab(char **map);
int					check_access(char *path, t_data *data, int index);
int					check_fd(char *path, char **text_file, int i);
int					parse_first_line(char **map);
// get_next_line.c
char				*get_next_line(int fd);
// raycast.c
int					render(t_data *data);
// print.c
void				print_line(t_data *data, t_dda *dda, t_raycast *rc, int x);
void				print_minimap(t_data *data);
// map.c
char				first_char(char *str);
char				**parse_file(const char *filename, t_data *data);
char				last_char(char *str);
// player.c
void				get_player_position(t_data *data);
// textures.c
int					get_texture(t_data *data, size_t i, char *path);
void				print_c_f(t_data *data, int x, int y);
char				**fetch_textures_file(const char *path, int count, int i,
						t_data *data);
// parsing.c
int					parse_error(t_data *data);
// is_here.c
int					is_ceiling_color(char **text);
int					is_floor_color(char **text);
int					is_text_paths(char **text);
int					is_map(char **map);
int					is_player(char **map);
// is_valid.c
int					is_valid_player(char **map);
int					is_valid_map(char **map);
int					is_val_char(char c);
// free.c
void				free_map(char **map);
int					error_parse_cleanup(t_data *data);
void				free_img(t_data *data, void *mlx);
// launch.c
bool				check_args(t_data *data, char **argv);
bool				manage_map(t_data *data, char **argv);
int					init_mlx(t_data *data);
int					mlx_error(t_data *data, int i);
int					is_cub(char **arg);
// movement_keypress.c
void				manage_w(t_data *data);
void				manage_s(t_data *data);
void				manage_a(t_data *data);
void				manage_d(t_data *data);
// view_keypress.c
void				manage_ra(t_data *data);
void				manage_la(t_data *data);
void				print_pix(t_render *rnd, t_data *data, int y, int x);
char				**get_map_helper(int fd, t_point point, char **map);
// map_utils.c
bool				is_ok(char *line, int count, t_point point);
// parse_helper.c
char				**get_map_helper(int fd, t_point point, char **map);
int					check_rgb_args(char *str);
int					check_text_args(char *str);
void				init_dbt(t_dbt *dbt);
// exist.c
bool				dont_exist_helper(char **map, int i, int j);
bool				dont_exist(char **map, int i, int j);
// movement_keypress_utils.c
int					can_move(t_data *data, double new_x, double new_y);
void				normalize_dir(t_data *data);
int					error_handler(t_data *data);
int					is_empty(char *str);

#endif
