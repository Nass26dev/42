/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:14:55 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 12:32:02 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipes(int pipe1, int pipe2)
{
	close(pipe1);
	close(pipe2);
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

void	free_args(t_args args)
{
	int	i;

	i = 0;
	if (args.cmd)
	{
		while (args.cmd[i])
		{
			if (args.cmd[i])
				free(args.cmd[i++]);
		}
		if (args.cmd[i])
			free(args.cmd[i]);
		free(args.cmd);
	}
	if (args.infile)
		free(args.infile);
	if (args.outfile)
		free(args.outfile);
}

char	*check_access(char *cmd_path, char **s_path)
{
	if (access(cmd_path, F_OK | X_OK) == 0)
	{
		free_splitted(s_path);
		return (cmd_path);
	}
	return (NULL);
}

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	free_split(splitted, i);
}
