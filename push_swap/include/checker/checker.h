/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:00:57 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/29 19:57:52 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int		value;
	int		path;
	int		target;
}			t_node;

typedef struct s_stack
{
	t_node	**arr;
	int		top;
}			t_stack;

typedef enum s_error
{
	ERROR,
	OK
}			t_error;

// gnl
char		*get_next_line(int fd);
// launcher.c
void		checker_one_arg(char **argv);
void		checker_several_args(int argc, char **argv);
void		exit_program(void);
// driver.c
void		checker(t_stack *a, t_stack *b);
void		free_all(t_stack *a, t_stack *b, int argc);
// create_stack.c
t_stack		*create_stack_one_arg(int argc, char **argv);
t_stack		*create_stack(int argc, char **argv);
t_error		add_to_stack(t_stack *a, int nb);
long int	ft_atol(const char *str);
// verification.c
bool		is_sorted(t_stack *a);
// error.c
t_error		verif_one_arg(char *str);
t_error		verif(int argc, char **argv);
t_error		is_duplicates(t_stack *a);
// split.c
void		free_split(char **split, int i);
char		**ft_split(const char *s, char c);
// free_launcher_one_arg
void		case_dup_one_arg(t_stack *a, t_stack *b, char **splitted, int size);
void		case_b_one_arg(t_stack *a, char **splitted, int size);
void		case_a_one_arg(char **splitted, int size);
// free_launcher
void		case_dup(t_stack *a, t_stack *b, int argc);
void		case_b(t_stack *a);
// init_b
t_stack		*init_b(int argc);
t_stack		*init_b_one_arg(int argc);

#endif