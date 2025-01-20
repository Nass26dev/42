/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:40:15 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/20 17:35:50 by nyousfi          ###   ########.fr       */
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
			close_pipes(e.pipefd[0], e.pipefd[1]);
			close_pipes(e.saved_stdin, e.saved_stdout);
			close(e.fd);
			free_splitted(e.s_cmd);
			free(e.temp);
			free_args(args);
			if (args.is_hd == 1)
				unlink(args.infile);
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
		close_pipes(e.pipefd[0], e.pipefd[1]);
		close_pipes(e.saved_stdin, e.saved_stdout);
		close(e.fd);
		free_splitted(e.s_cmd);
		free(e.temp);
		if (args.is_hd == 1)
			unlink(args.infile);
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
		close_pipes(e.pipefd[0], e.pipefd[1]);
		close_pipes(e.saved_stdin, e.saved_stdout);
		close(e.fd);
		free_splitted(e.s_cmd);
		if (args.is_hd == 1)
			unlink(args.infile);
		free_args(args);
		exit(EXIT_FAILURE);
	}
}

void	check_child_success(pid_t pid, int rd, int wr, t_args args)
{
	t_exit	ex;

	waitpid(pid, &ex.status, 0);
	if (WIFEXITED(ex.status))
	{
		ex.exit_status = WEXITSTATUS(ex.status);
		if (ex.exit_status != EXIT_SUCCESS)
		{
			close_pipes(rd, wr);
			if (args.is_hd == 1)
				unlink(args.infile);
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_args(t_args args, char **env)
{
	t_error	e;

	e = init_e();
	pipe(e.pipefd);
	e.fd = open(args.infile, O_RDONLY);
	if (e.fd == -1)
	{
		perror("open error for infile");
		if (args.is_hd == 1)
			unlink(args.infile);
		close_pipes(e.pipefd[1], e.pipefd[0]);
		free_args(args);
		exit(EXIT_FAILURE);
	}
	dup_std(e);
	while (args.cmd[++e.i])
	{
		e.s_cmd = ft_split(args.cmd[e.i], ' ');
		e.temp = find_path(e.s_cmd[0], env);
		is_unfounded(e, args);
		test_flags(e, args, env);
		free_splitted(e.s_cmd);
		free(e.temp);
	}
	restore_std(e.saved_stdin, e.saved_stdout);
}
