/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdt_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:39:00 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 17:15:02 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	cdt_count_greater_down_col(int **board, int ty)
{
	int	max;
	int	counter;
	int	x;

	max = 0;
	counter = 0;
	x = 4;
	while (x >= 1)
	{
		if (board[x][ty] > max)
		{
			max = board[x][ty];
			counter++;
		}
		x--;
	}
	if (counter == board[5][ty])
		return (1);
	else
		return (0);
}

int	cdt_count_greater_up_col(int **board, int ty)
{
	int	max;
	int	counter;
	int	x;

	max = 0;
	counter = 0;
	x = 1;
	while (x <= 4)
	{
		if (board[x][ty] > max)
		{
			max = board[x][ty];
			counter++;
		}
		x++;
	}
	if (counter == board[0][ty])
		return (1);
	else
		return (0);
}

int	cdt_count_greater_down_line(int **board, int tx)
{
	int	max;
	int	counter;
	int	y;

	max = 0;
	counter = 0;
	y = 4;
	while (y >= 1)
	{
		if (board[tx][y] > max)
		{
			max = board[tx][y];
			counter++;
		}
		y--;
	}
	if (counter == board[tx][5])
		return (1);
	else
		return (0);
}

int	cdt_count_greater_up_line(int **board, int tx)
{
	int	max;
	int	counter;
	int	y;

	max = 0;
	counter = 0;
	y = 1;
	while (y <= 4)
	{
		if (board[tx][y] > max)
		{
			max = board[tx][y];
			counter++;
		}
		y++;
	}
	if (counter == board[tx][0])
		return (1);
	else
		return (0);
}
