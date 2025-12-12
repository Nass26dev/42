/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:59:18 by nass              #+#    #+#             */
/*   Updated: 2025/02/19 14:48:25 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_lst(t_map *lst)
{
	t_map	*next;
	t_map	*current;
	t_down	*current_down;
	t_down	*next_down;

	current = lst;
	while (current)
	{
		current_down = current->down;
		while (current_down)
		{
			next_down = current_down->next;
			free(current_down);
			current_down = next_down;
		}
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_function(int nf, int nfl, int nfs, ...)
{
	int		i;
	t_free	f;

	va_list(args);
	va_start(args, nfs);
	i = -1;
	while (++i < nf)
	{
		f.ptr = va_arg(args, void *);
		free(f.ptr);
	}
	i = -1;
	while (++i < nfl)
	{
		f.map = va_arg(args, t_map *);
		free_lst(f.map);
	}
	i = -1;
	while (++i < nfs)
	{
		f.split = va_arg(args, char **);
		free_split(f.split);
	}
	va_end(args);
}
