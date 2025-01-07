/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:36:54 by nass              #+#    #+#             */
/*   Updated: 2024/12/29 19:50:07 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_list	*read_file(int fd, t_param *param)
{
	t_list	*lst;
	char	*str;
	int		x;
	char	**splitted;
	int		j;

	lst = NULL;
	x = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		add_node(&lst, x, param);
		splitted = ft_split(str, ' ');
		add_nodes_down(&lst, splitted, param);
		j = 0;
		while (splitted[j])
			j++;
		free_split(splitted, j);
		free(str);
		x++;
	}
	return (lst);
}
