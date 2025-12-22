/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:12:05 by tmarion           #+#    #+#             */
/*   Updated: 2025/01/17 14:58:59 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_get_memset(void *source, int neww, size_t nb)
{
	size_t	i;
	char	*src;

	i = 0;
	src = (char *)source;
	while (i < nb)
	{
		src[i] = neww;
		i++;
	}
}

static char	*auxiliary_fd(int fd, char *buffer, char *temp, int *len)
{
	*len = read(fd, buffer, BUFFER_SIZE);
	if (*len == -1)
		return (free(temp), NULL);
	buffer[*len] = '\0';
	if (!temp)
	{
		temp = ft_strdup(buffer);
		if (!temp)
			return (NULL);
	}
	if (*len > 0)
		temp = ft_strjoin(temp, buffer);
	return (temp);
}

static char	*get_fd(int fd, char *buffer, char *temp, int *len)
{
	int			i;
	static int	trigger;

	i = -1;
	temp = ft_strdup(buffer);
	if (!temp)
		return (ft_get_memset(buffer, 0, BUFFER_SIZE), NULL);
	while (*len > 0 && i == -1)
	{
		temp = auxiliary_fd(fd, buffer, temp, &*len);
		if (!temp || *len == -1)
			return (ft_get_memset(buffer, 0, BUFFER_SIZE), NULL);
		i = findnewline(buffer);
	}
	ft_strlcpy(buffer, buffer + i + 1, BUFFER_SIZE);
	if (temp[0] == '\0' && buffer[0] == '\0')
		return (ft_get_memset(buffer, 0, BUFFER_SIZE), free(temp), NULL);
	if (*len == 0 && trigger < 1)
		return (trigger++, temp);
	if (*len == 0)
		return (trigger = 0, buffer[0] = 0, free (temp), NULL);
	return (trigger = 0, temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			len;
	static int	trigger = 0;
	char		*temp;

	len = BUFFER_SIZE;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (ft_get_memset(buffer, 0, BUFFER_SIZE), NULL);
	if (findnewline(buffer) >= 0)
	{
		temp = ft_strdup(buffer);
		if (!temp)
			return (ft_get_memset(buffer, 0, BUFFER_SIZE), NULL);
		temp[findnewline(temp) + 1] = '\0';
		ft_strlcpy(buffer, buffer + findnewline(buffer) + 1, BUFFER_SIZE);
		return (temp);
	}
	temp = get_fd(fd, buffer, temp, &len);
	if ((len < BUFFER_SIZE && len >= 0)
		&& findnewline(buffer) == -1 && trigger == 1)
		return (trigger++, temp);
	if (findnewline(temp) >= 0)
		temp [findnewline(temp) + 1] = '\0';
	return (trigger = 0, temp);
}
