/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:59:49 by nass              #+#    #+#             */
/*   Updated: 2024/12/24 03:43:32 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

t_error	read_and_stock(t_gnl_list **stock, int fd, char *buffer)
{
	ssize_t	nb_bytes;

	nb_bytes = 1;
	while (lst_search_nl(*stock) == FALSE && nb_bytes > 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1 || (nb_bytes == 0 && line_len(*stock) == 0))
			return (buffer[0] = 0, ERROR);
		buffer[nb_bytes] = 0;
		if (lst_add_last(stock, buffer) == ERROR)
			return (ERROR);
	}
	return (OK);
}

void	recup_exedent(t_gnl_list *stock, char *buffer)
{
	ssize_t	i;

	i = 0;
	while (stock->next)
		stock = stock->next;
	while (stock->buffer[i] && stock->buffer[i] != '\n')
		i++;
	if (stock->buffer[i] == '\n')
		i++;
	while (stock->buffer[i])
		*buffer++ = stock->buffer[i++];
	*buffer = 0;
}

t_error	free_function(t_gnl_list **stock, char *line)
{
	t_gnl_list	*current;
	t_gnl_list	*next;

	current = *stock;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(line);
	*stock = NULL;
	return (ERROR);
}

t_error	line_and_exedent(t_gnl_list **stock, char **line, char *buffer)
{
	*line = recup_line(*stock, *line);
	if (!*line)
		return (free_function(stock, *line));
	if (*line[0] == 0)
		return (free_function(stock, *line));
	recup_exedent(*stock, buffer);
	free_function(stock, NULL);
	return (OK);
}

char	*get_next_line(int fd)
{
	static char	buffer[NB_FD_MAX][BUFFER_SIZE + 1];
	t_gnl_list		*stock;
	char		*line;

	if (fd < 0 || fd >= NB_FD_MAX || BUFFER_SIZE <= 0 || NB_FD_MAX <= 0)
		return (NULL);
	stock = search_exedent(buffer[fd]);
	if (!stock)
		return (NULL);
	line = NULL;
	if (read_and_stock(&stock, fd, buffer[fd]) == ERROR)
		return ((char *)free_function(&stock, line));
	if (line_and_exedent(&stock, &line, buffer[fd]) == ERROR)
		return (NULL);
	return (line);
}
