/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:47:26 by nass              #+#    #+#             */
/*   Updated: 2025/01/23 18:23:09 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	add_yz(char *line, t_map **map)
{
	t_map	*actual;
	t_down	*new;
	t_down	**current;
	char	**s_line;
	int		y;

	s_line = ft_split(line, ' ');
	if (!s_line)
	{
		free_function(1, 1, 0, line, *map);
		exit(EXIT_FAILURE);
	}
	y = -1;
	actual = *map;
	while (actual->next)
		actual = actual->next;
	current = &actual->down;
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
