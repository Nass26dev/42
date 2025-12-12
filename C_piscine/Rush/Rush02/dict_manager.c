/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpilo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:31:06 by mpilo             #+#    #+#             */
/*   Updated: 2024/08/25 19:40:47 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	size_evaluator(int fd)
{
	int		i;
	char	*co;

	i = 0;
	co = "";
	while (read(fd, &co, 1))
		i++;
	close(fd);
	return (i);
}

int	val_counter(char *content, int size)
{
	int	i;
	int	sep_count;

	i = 0;
	sep_count = 0;
	while (i < size)
	{
		if (content[i] == '\n')
			sep_count++;
		i++;
	}
	return (sep_count);
}

char	*ft_dict_opener(char *path)
{
	int		dict_f;
	int		size;
	char	*file_buffer;

	file_buffer = NULL;
	dict_f = open(path, O_RDONLY);
	if (dict_f == -1)
		return ("Dict Error\n");
	size = size_evaluator(dict_f);
	file_buffer = malloc(size);
	if (!file_buffer)
		return ("Dict Error\n");
	dict_f = open(path, O_RDONLY);
	read(dict_f, file_buffer, size);
	return (file_buffer);
}
