/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflechel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:10:51 by sflechel          #+#    #+#             */
/*   Updated: 2024/08/18 18:22:34 by sflechel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	ft_print_error(void);
void	ft_write_board(int **board);

int		**ft_generate_board(int *views);
int		*ft_generate_views(char *str);

int		cdt_count_greater_down_col(int **board, int ty);
int		cdt_count_greater_down_line(int **board, int tx);
int		cdt_count_greater_up_col(int **board, int ty);
int		cdt_count_greater_up_line(int **board, int tx);

int		cdt_not_already_there(int **board, int x, int y);

int		ft_conditions_correct(int **board, int i);
int		ft_input_is_correct(char *str);

int		ft_skyscraper_rec(int **board, int i);

#endif
