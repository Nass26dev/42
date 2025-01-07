/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:32:59 by nass              #+#    #+#             */
/*   Updated: 2024/12/29 19:51:08 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// linked list with y and z value
typedef struct s_down
{
	int				y;
	int				z;
	struct s_down	*next;
}					t_down;

// linked list with x value and down linked list
typedef struct s_list
{
	int				x;
	t_down			*down;
	struct s_list	*next;
}					t_list;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_param
{
	void			*mlx;
	void			*win;
	int				zoom_factor;
	int				offset_x;
	int				offset_y;
	int				proj;
	double			angle_x;
	double			angle_y;
	double			degrees;
	t_list			*lst;
}					t_param;

typedef struct s_bresenham
{
	// abs diff for x
	int				diff_x;
	// abs diff for y
	int				diff_y;
	int				steps;
	// nb incrementation for x
	float			x_inc;
	// nb incrementation for y
	float			y_inc;
	// transparency
	float			t;
	// rest
	float			x;
	float			y;
	int				i;
	int				color;
}					t_bresenham;

typedef struct s_render
{
	t_point			proj;
	t_point			next_proj;
	t_point			one;
	t_point			two;
	t_list			*current;
	t_list			*next;
	t_down			*current_down;
	t_down			*next_down;
	int				color;
	int				color2;
}					t_render;

#endif