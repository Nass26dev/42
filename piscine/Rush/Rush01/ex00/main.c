/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:01:10 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/18 17:16:27 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	*views;
	int	**board;

	if (argc != 2)
		ft_print_error();
	else if (ft_input_is_correct(argv[1]) == 1)
		ft_print_error();
	else
	{
		views = ft_generate_views(argv[1]);
		board = ft_generate_board(views);
		ft_skyscraper_rec(board, 0);
	}
	return (0);
}
