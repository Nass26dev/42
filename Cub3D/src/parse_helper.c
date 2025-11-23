/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:41:10 by tmarion           #+#    #+#             */
/*   Updated: 2025/11/10 12:33:55 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_rgb_len(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_split(str, ',');
	if (!split)
		return (1);
	while (split[i])
	{
		j = 0;
		while (ft_isdigit(split[i][j]))
			j++;
		if (j < 1 || j > 3)
		{
			free_map(split);
			return (1);
		}
		i++;
	}
	free_map(split);
	return (0);
}

int	check_rgb_args(char *str)
{
	size_t	i;
	size_t	count;
	char	*temp;

	count = 0;
	i = 0;
	temp = str;
	while (*temp != 0 && !ft_isdigit(*temp) && *temp != ',')
		temp++;
	if (*temp == ',')
		return (1);
	if (check_rgb_len(temp))
		return (1);
	while (str[i])
	{
		if (str[i] != ',' && str[i] != 32 && str[i] != 9 && str[i] != 'C'
			&& str[i] != 'F' && ft_isdigit(str[i]) == 0 && str[i] != 10)
			return (1);
		if (str[i] == 'C' || str[i] == 'F')
			count++;
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

char	**get_map_helper(int fd, t_point point, char **map)
{
	char	*line;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < point.y || line)
	{
		line = get_next_line(fd);
		count++;
		if (!line)
			break ;
		else
			map[i++] = line;
	}
	map[i] = NULL;
	return (map);
}

int	check_text_args(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] != 32 && str[i] != 9)
			return (0);
		i++;
	}
	return (1);
}

void	init_dbt(t_dbt *dbt)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		dbt[i].img = NULL;
		dbt[i].addr = NULL;
		dbt[i].width = 0;
		dbt[i].height = 0;
		dbt[i].bpp = 0;
		dbt[i].line_len = 0;
		dbt[i].endian = 0;
		dbt[i].init = 0;
		i++;
	}
}
