/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:28:39 by nass              #+#    #+#             */
/*   Updated: 2025/01/07 12:36:19 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef CHILD_PID
#  define CHILD_PID 0
# endif

typedef struct s_error
{
	char	**s_cmd;
	char	*temp;
	int		i;
	pid_t	pid;
	int		status;
	int		exit_status;
	int		pipefd[2];
	int		fd;
	int		saved_stdin;
	int		saved_stdout;
}			t_error;

typedef struct s_exit
{
	int		exit_status;
	int		status;
}			t_exit;

typedef struct s_args
{
	int		i;
	bool	is_hd;
	char	*stopper;
	char	**cmd;
	char	*infile;
	char	*outfile;
}			t_args;

int			open_file(char *name, int boolean);
char		*find_path(char *cmd, char **env);
void		free_splitted(char **splitted);
t_args		get_args(int argc, char **argv);
void		check_args(t_args args, char **env);
void		free_args(t_args args);
void		restore_std(t_error e);
void		is_unfounded(t_error e, t_args args);
void		test_flags(t_error e, t_args args, char **env);
void		check_child_success(pid_t pid, int *pipefd, t_exit e, t_args args);
t_args		case_here_doc(int argc, char **argv);
void		pipeline(t_args *args, int *main_pipefd, char **env);
void		last_child(t_args args, int *pipefd, char **env);
void		execute(char *cmd, char **env);
void		close_pipe(int pipe1, int pipe2);
void		main_part(t_args args, int *pipefd, char **env, t_exit e);
void		child(t_args args, int *pipefd, char **env);

#endif