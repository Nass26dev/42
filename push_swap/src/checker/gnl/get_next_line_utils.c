/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:12:56 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 17:39:32 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker/get_next_line.h"

t_boolean	lst_search_nl(t_list *stock)
{
	t_list	*current;
	int		i;

	current = stock;
	while (current)
	{
		i = -1;
		while (current->buffer[++i])
		{
			if (current->buffer[i] == '\n')
				return (TRUE);
		}
		current = current->next;
	}
	return (FALSE);
}

t_error	lst_add_last(t_list **stock, char *buffer)
{
	t_list	*last;
	t_list	*new;
	t_list	*current;
	int		i;

	i = -1;
	new = malloc(sizeof(t_list));
	if (!new)
		return (ERROR);
	while (buffer[++i])
		new->buffer[i] = buffer[i];
	new->buffer[i] = 0;
	new->next = NULL;
	if (!*stock)
	{
		*stock = new;
		return (OK);
	}
	current = *stock;
	while (current->next)
		current = current->next;
	last = current;
	last->next = new;
	return (OK);
}

int	line_len(t_list *stock)
{
	t_list	*current;
	int		i;
	int		len;

	current = stock;
	len = 0;
	while (current)
	{
		i = -1;
		while (current->buffer[++i])
		{
			len++;
			if (current->buffer[i] == '\n')
				break ;
		}
		current = current->next;
	}
	return (len);
}

char	*recup_line(t_list *stock, char *line)
{
	t_list	*current;
	int		i;
	int		j;

	j = 0;
	current = stock;
	line = malloc(line_len(stock) + 1);
	if (!line)
		return (NULL);
	while (current)
	{
		i = -1;
		while (current->buffer[++i])
		{
			line[j++] = current->buffer[i];
			if (current->buffer[i] == '\n')
				break ;
		}
		current = current->next;
	}
	line[j] = 0;
	return (line);
}

t_list	*search_exedent(char *buffer)
{
	t_list	*new;
	ssize_t	i;

	i = -1;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	while (buffer[++i])
		new->buffer[i] = buffer[i];
	new->buffer[i] = 0;
	new->next = NULL;
	return (new);
}
