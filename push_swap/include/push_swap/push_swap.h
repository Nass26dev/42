/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:15:10 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/29 19:57:39 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
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

typedef struct s_rot
{
	int		rot;
	int		rotb;
}			t_rot;

typedef struct s_variable
{
	int		a_top;
	int		b_top;
	int		a_bot;
	int		b_bot;
}			t_variable;

// create_stack.c
long int	ft_atol(const char *str);
t_stack		*create_stack_one_arg(int argc, char **argv);
t_stack		*create_stack(int argc, char **argv);
t_error		add_to_stack(t_stack *a, int nb);

// error.c
t_error		is_duplicates(t_stack *a);
t_error		verif(int argc, char **argv);
t_error		verif_one_arg(char *str);

// free_launcher_one_arg.c
void		case_dup_one_arg(t_stack *a, t_stack *b, t_stack *cpy, int size);
void		case_cpy_one_arg(t_stack *a, t_stack *b, char **splitted, int size);
void		case_b_one_arg(t_stack *a, char **splitted, int size);
void		case_a_one_arg(char **splitted, int size);

// free_launcher.c
void		case_dup(t_stack *a, t_stack *b, t_stack *cpy, int argc);
void		case_cpy(t_stack *a, t_stack *b);
void		case_b(t_stack *a);

// init_b.c
t_stack		*init_b(int argc);
t_stack		*init_b_one_arg(int argc);

// launcher.c
void		exit_program(void);
void		one_arg(char **argv);
void		several_args(int argc, char **argv);

// do_rotations_ww.c
void		final_rotations_ww(t_stack *a);
void		do_rotations_and_push_ww(t_stack *a, t_stack *b);
void		rrb_or_rb_ww(t_stack *b, int element, int index_final);
void		rra_or_ra_ww(t_stack *a, int target, int index_big);
void		rrr_or_rr_ww(t_stack *a, t_stack *b, int index_f, int index_b);

// sort_cpy.c
void		sort_cpy(t_stack *cpy, t_stack *b);
void		sort_little_stacks_ww(t_stack *a, t_stack *b);
void		three_sort_ww(t_stack *a);

// cost.c
void		cost_logic(t_stack *a, t_stack *b, t_variable *var, int i);
int			cost_calc(t_variable *var);
int			cost_push(t_stack *a, t_stack *b);

// find.c
int			find_biggest(t_stack *a);
int			find_smallest_path(t_stack *a);
int			find_next_bigger(t_stack *b, int top);
int			find_quickest_path(t_stack *b, int search);
int			find_smallest(t_stack *a);

// find2.c
int			find_max(t_stack *b);
int			find_min(t_stack *a);
int			find_closest_biggest(int value, t_stack *a);
int			find_closest_smallest(int value, t_stack *b);

// ft_split.c
void		free_split(char **split, int i);
char		**ft_split(const char *s, char c);

// verification.c
bool		there_is_bigger(t_stack *b, int top);
bool		is_sorted(t_stack *a);

// do_rotations.c
void		final_rotations(t_stack *a);
void		do_rotations_and_push(t_stack *a, t_stack *b);
void		rrb_or_rb(t_stack *b, int element, int index_final);
void		rra_or_ra(t_stack *a, int target, int index_big);
void		rrr_or_rr(t_stack *a, t_stack *b, int index_final, int index_big);

// driver.c
void		push_swap(t_stack *a, t_stack *b, t_stack *cpy);
void		push_swap_cpy(t_stack *a, t_stack *b);
void		free_all(t_stack *a, t_stack *b, t_stack *cpy, int argc);

// sort.c
void		sort(t_stack *a, t_stack *b, t_stack *cpy);
void		little_stacks_sort(t_stack *a, t_stack *b);
void		three_sort(t_stack *a);

#endif
