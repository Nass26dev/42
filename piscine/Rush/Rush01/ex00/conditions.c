/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflechel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:51:54 by sflechel          #+#    #+#             */
/*   Updated: 2024/08/18 17:15:13 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	cdt_not_already_there(int **board, int x, int y)
{
	int	cx;
	int	cy;
	int	height;

	height = board[x][y];
	cy = 1;
	while (cy < 5)
	{
		if (board[x][cy] == height && cy != y)
			return (0);
		cy++;
	}
	cx = 1;
	while (cx < 5)
	{
		if (board[cx][y] == height && cx != x)
			return (0);
		cx++;
	}
	return (1);
}

int	ft_conditions_correct(int **board, int i)
{
	int	counter;
	int	target;

	target = 1;
	counter = 0;
	if (cdt_not_already_there(board, i / 4 + 1, i % 4 + 1) == 1)
		counter++;
	if (i % 4 + 1 == 4)
	{
		if (cdt_count_greater_up_line(board, i / 4 + 1) == 1)
			counter++;
		if (cdt_count_greater_down_line(board, i / 4 + 1) == 1)
			counter++;
		target += 2;
	}
	if (i / 4 + 1 == 4)
	{
		if (cdt_count_greater_up_col(board, i % 4 + 1) == 1)
			counter++;
		if (cdt_count_greater_down_col(board, i % 4 + 1) == 1)
			counter++;
		target += 2;
	}
	return (counter == target || i == 0);
}
