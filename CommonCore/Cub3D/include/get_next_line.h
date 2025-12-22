/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:06:14 by nyousfi           #+#    #+#             */
/*   Updated: 2025/09/18 13:17:07 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef NB_FD_MAX
#  define NB_FD_MAX 1024
# endif

typedef struct s_list
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_list;

typedef enum s_boolean
{
	FALSE,
	TRUE
}					t_boolean;

typedef enum s_error
{
	ERROR,
	OK
}					t_error;

char				*recup_line(t_list *stock, char *line);
int					line_len(t_list *stock);
char				*get_next_line(int fd);
void				recup_exedent(t_list *stock, char *buffer);
t_error				read_and_stock(t_list **stock, int fd, char *buffer);
t_error				lst_add_last(t_list **stock, char *buffer);
t_boolean			lst_search_nl(t_list *stock);
t_error				free_function(t_list **stock, char *line);
t_error				line_and_exedent(t_list **stock, char **line, char *buffer);
t_list				*search_exedent(char *buffer);

#endif