/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:36:04 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 20:22:40 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	*ft_generate_views(char *str)
{
	int	*views;
	int	i;

	views = malloc(16 * (sizeof(int)));
	if (views == 0)
		ft_print_error();
	i = 0;
	while (*str && i < 16)
	{
		if (*str >= '0' && *str <= '9')
		{
			views[i] = *str - '0';
			i++;
		}
		str++;
	}
	return (views);
}

int	**ft_generate_board(int *views)
{
	int	**board;
	int	i;

	i = 0;
	board = malloc((6 + 1) * sizeof(int *));
	if (board == 0)
		ft_print_error();
	while (i < 6)
	{
		board[i] = malloc(6 * sizeof(int));
		if (board[i] == 0)
			ft_print_error();
		i++;
	}
	board[6] = 0;
	i = 0;
	while (i < 16)
	{
		if (i < 4)
			board[0][i + 1] = views[i];
		else if (i < 8)
			board[5][i % 4 + 1] = views[i];
		else if (i < 12)
			board[i % 4 + 1][0] = views[i];
		else if (i < 16)
			board[i % 4 + 1][5] = views[i];
		i++;
	}
	return (board);
}
