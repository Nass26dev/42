/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:33:21 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 17:16:41 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_skyscraper_rec(int **board, int i)
{
	int	z;

	if (i > 15)
	{
		ft_write_board(board);
		return (1);
	}
	while (i / 4 + 1 < 5 && i % 4 + 1 < 5)
	{
		z = 1;
		while (z < 5)
		{
			board[i / 4 + 1][i % 4 + 1] = z;
			if (ft_conditions_correct(board, i) == 1)
				if (ft_skyscraper_rec(board, i + 1) == 1)
					return (1);
			board[i / 4 + 1][i % 4 + 1] = 0;
			if (z == 4 && i == 0)
				ft_print_error();
			if (z == 4)
				return (0);
			z++;
		}
	}
	return (0);
}
