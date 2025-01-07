/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:40:15 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/07 12:31:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_args(t_args args)
{
	int	i;

	i = 0;
	while (args.cmd[i])
		free(args.cmd[i++]);
	free(args.cmd[i]);
	free(args.cmd);
	free(args.infile);
	free(args.outfile);
}

void	check_child_success(pid_t pid, int *pipefd, t_exit e, t_args args)
{
	waitpid(pid, &e.status, 0);
	if (WIFEXITED(e.status))
	{
		e.exit_status = WEXITSTATUS(e.status);
		if (e.exit_status != EXIT_SUCCESS)
		{
			free_args(args);
			close_pipe(pipefd[0], pipefd[1]);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_args(t_args args, char **env)
{
	t_error	e;

	pipe(e.pipefd);
	e.fd = open(args.infile, O_RDONLY);
	if (e.fd == -1)
	{
		perror("open error for infile");
		exit(EXIT_FAILURE);
	}
	e.saved_stdin = dup(STDIN_FILENO);
	e.saved_stdout = dup(STDOUT_FILENO);
	dup2(e.fd, STDIN_FILENO);
	dup2(e.pipefd[1], STDOUT_FILENO);
	e.i = 0;
	while (args.cmd[e.i])
	{
		e.s_cmd = ft_split(args.cmd[e.i], ' ');
		e.temp = find_path(e.s_cmd[0], env);
		is_unfounded(e, args);
		test_flags(e, args, env);
		free_splitted(e.s_cmd);
		free(e.temp);
		e.i++;
	}
	restore_std(e);
}
