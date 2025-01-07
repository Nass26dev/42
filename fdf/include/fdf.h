/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:44:48 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/29 19:51:18 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "define.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
void		add_node(t_list **lst, int x, t_param *param);
void		add_nodes_down(t_list **lst, char **splitted, t_param *param);
void		free_lst(t_list *lst);
long int	ft_atol(const char *str);
char		**ft_split(const char *s, char c);
void		free_split(char **split, int i);
t_list		*read_file(int fd, t_param *param);
void		render_3d(t_param *param);
int			get_color(int z);
t_point		choose_proj(int x, int y, int z, t_param *param);
int			insert_color(int color_start, int color_end, float t);
t_rgb		hex_to_rgb(int hex);
int			close_window(int keycode, void *param);

#endif