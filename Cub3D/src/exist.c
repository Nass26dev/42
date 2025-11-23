/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:03:11 by tmarion           #+#    #+#             */
/*   Updated: 2025/11/05 14:05:32 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	dont_exist_helper(char **map, int i, int j)
{
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1')
		return (true);
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1')
		return (true);
	if (map[i][j + 1] && map[i][j + 1] != '0' && map[i][j + 1] != '1')
		return (true);
	return (false);
}

bool	dont_exist(char **map, int i, int j)
{
	int	temp;

	temp = 0;
	if (i < 0 || j < 0 || i - 1 < 0 || j - 1 < 0)
		return (true);
	if (!map || !*map)
		return (true);
	while (temp < j)
	{
		if (!map[i + 1][temp])
			return (true);
		temp++;
	}
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1')
		return (true);
	temp = 0;
	while (temp < j)
	{
		if (!map[i - 1][temp])
			return (true);
		temp++;
	}
	return (dont_exist_helper(map, i, j));
}
