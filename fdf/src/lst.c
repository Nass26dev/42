/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:50:26 by nass              #+#    #+#             */
/*   Updated: 2024/12/29 19:50:03 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_lst(t_list *lst)
{
	t_list	*next;
	t_list	*current;
	t_down	*current2;
	t_down	*next2;

	current = lst;
	while (current)
	{
		current2 = current->down;
		while (current2)
		{
			next2 = current2->next;
			free(current2);
			current2 = next2;
		}
		next = current->next;
		free(current);
		current = next;
	}
}

void	add_node_to_down(t_down **down, int z, int y, t_param *param)
{
	t_down	*current;
	t_down	*new;

	new = malloc(sizeof(t_down));
	if (!new)
		close_window(0, param);
	new->next = NULL;
	new->y = y;
	new->z = z;
	if (!*down)
	{
		*down = new;
		return ;
	}
	current = *down;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	add_nodes_down(t_list **lst, char **splitted, t_param *param)
{
	t_list	*current;
	int		i;

	current = *lst;
	while (current->next)
		current = current->next;
	i = -1;
	while (splitted[++i])
		add_node_to_down(&current->down, ft_atol(splitted[i]), i, param);
}

void	add_node(t_list **lst, int x, t_param *param)
{
	t_list	*current;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		close_window(0, param);
	new->next = NULL;
	new->x = x;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
