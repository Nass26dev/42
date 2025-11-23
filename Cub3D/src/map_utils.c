/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:05:29 by nass              #+#    #+#             */
/*   Updated: 2025/09/12 15:08:52 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_ok(char *line, int count, t_point point)
{
	if ((first_char(line) != '1' && first_char(line) != '0'
			&& first_char(line) != 'N' && first_char(line) != 'W'
			&& first_char(line) != 'S' && first_char(line) != 'E')
		|| count < point.text_tab_len)
		return (true);
	return (false);
}
