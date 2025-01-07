/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:06:02 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/07 10:41:01 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	analyse_status(t_error e, t_args args)
{
	waitpid(e.pid, &e.status, 0);
	if (WIFEXITED(e.status))
	{
		e.exit_status = WEXITSTATUS(e.status);
		if (e.exit_status != 0)
		{
			close(e.pipefd[0]);
			close(e.pipefd[1]);
			close(e.saved_stdin);
			close(e.saved_stdout);
			close(e.fd);
			free_splitted(e.s_cmd);
			free(e.temp);
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
}

void	test_flags(t_error e, t_args args, char **env)
{
	e.pid = fork();
	if (e.pid == 0)
	{
		execve(e.temp, e.s_cmd, env);
		perror("execve failed");
		close(e.pipefd[0]);
		close(e.pipefd[1]);
		close(e.saved_stdin);
		close(e.saved_stdout);
		close(e.fd);
		free_splitted(e.s_cmd);
		free(e.temp);
		free_args(args);
		exit(EXIT_FAILURE);
	}
	else
		analyse_status(e, args);
}

void	is_unfounded(t_error e, t_args args)
{
	if (!e.temp)
	{
		ft_putstr_fd("cmd not found : ", STDERR_FILENO);
		ft_putendl_fd(e.s_cmd[0], STDERR_FILENO);
		close(e.pipefd[0]);
		close(e.pipefd[1]);
		close(e.saved_stdin);
		close(e.saved_stdout);
		close(e.fd);
		free_args(args);
		free_splitted(e.s_cmd);
		exit(EXIT_FAILURE);
	}
}
