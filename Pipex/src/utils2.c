/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:14:55 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/14 15:59:41 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipes(int pipe1, int pipe2)
{
	close(pipe1);
	close(pipe2);
}

void	restore_std(t_error e)
{
	dup2(e.saved_stdin, STDIN_FILENO);
	dup2(e.saved_stdout, STDOUT_FILENO);
	close_pipes(e.saved_stdin, e.saved_stdout);
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
