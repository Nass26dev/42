/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:30:17 by nass              #+#    #+#             */
/*   Updated: 2025/02/19 14:11:02 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int	hex_to_int(const char *hex)
{
	unsigned int	result;
	char			c;
	int				digit;

	result = 0;
	hex += 2;
	while (*hex)
	{
		c = *hex;
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'a' && c <= 'f')
			digit = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			digit = c - 'A' + 10;
		else
			break ;
		result = (result << 4) | digit;
		hex++;
	}
	return (result);
}

bool	is_comma(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			return (true);
		i++;
	}
	return (false);
}

int	get_color(char *s_line)
{
	char	color[9];
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!is_comma(s_line))
		return (WHITE);
	while (s_line[i] != ',')
		i++;
	i++;
	while (s_line[i] && j <= 7)
		color[j++] = s_line[i++];
	color[j] = 0;
	return (hex_to_int(color));
}
