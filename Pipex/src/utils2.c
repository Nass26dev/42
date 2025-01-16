/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:14:55 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/16 14:01:02 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipes(int pipe1, int pipe2)
{
	close(pipe1);
	close(pipe2);
}

void	restore_std(int s_stdin, int s_stdout)
{
	dup2(s_stdin, STDIN_FILENO);
	dup2(s_stdout, STDOUT_FILENO);
	close_pipes(s_stdin, s_stdout);
}

void	dup_std(t_error e)
{
	e.saved_stdin = dup(STDIN_FILENO);
	e.saved_stdout = dup(STDOUT_FILENO);
	dup2(e.fd, STDIN_FILENO);
	dup2(e.pipefd[1], STDOUT_FILENO);
}

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

t_error	init_e(void)
{
	t_error	e;

	e.saved_stdin = 0;
	e.saved_stdout = 0;
	e.i = -1;
	return (e);
}
