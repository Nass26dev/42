/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:47:26 by nass              #+#    #+#             */
/*   Updated: 2025/02/19 14:36:31 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_down	**search_last(t_map **map)
{
	t_map	*actual;

	actual = *map;
	while (actual->next)
		actual = actual->next;
	return (&actual->down);
}

char	**split_line(char *line, t_map **map)
{
	char	**s_line;

	s_line = ft_split(line, ' ');
	if (!s_line)
	{
		free_function(1, 1, 0, line, *map);
		exit(EXIT_FAILURE);
	}
	return (s_line);
}

void	add_yz(char *line, t_map **map)
{
	t_down	*new;
	t_down	**current;
	char	**s_line;
	int		y;

	y = -1;
	s_line = split_line(line, map);
	current = search_last(map);
	while (s_line[++y])
	{
		new = malloc(sizeof(t_down));
		if (!new)
		{
			free_function(1, 1, 1, line, *map, s_line);
			exit(EXIT_FAILURE);
		}
		new->next = NULL;
		new->y = y;
		new->z = ft_atol(s_line[y]);
		new->color = get_color(s_line[y]);
		*current = new;
		current = &new->next;
	}
	free_split(s_line);
}

void	add_x(char *line, t_map **map, int x)
{
	t_map	*new;
	t_map	*current;

	new = malloc(sizeof(t_map));
	if (!new)
	{
		free_function(1, 1, 0, line, *map);
		exit(EXIT_FAILURE);
	}
	new->x = x;
	new->down = NULL;
	new->next = NULL;
	if (!*map)
		*map = new;
	else
	{
		current = *map;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	parse_file(char *filename, t_param *m)
{
	int		fd;
	char	*line;
	int		x;

	m->lst = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open error :");
		exit(1);
	}
	x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		add_x(line, &m->lst, x);
		add_yz(line, &m->lst);
		free(line);
		x++;
	}
	close(fd);
}
