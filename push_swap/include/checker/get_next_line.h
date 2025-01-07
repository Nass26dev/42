/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:12:20 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/13 11:12:25 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
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