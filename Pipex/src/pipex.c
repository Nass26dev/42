/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:47:26 by nass              #+#    #+#             */
/*   Updated: 2025/01/07 12:35:21 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = find_path(s_cmd[0], env);
	execve(path, s_cmd, env);
	perror("cmd not found : ");
	free_splitted(s_cmd);
	free(path);
}

void	last_child(t_args args, int *pipefd, char **env)
{
	int	fd;

	if (args.is_hd == 1)
		fd = open_file(args.outfile, 2);
	else
		fd = open_file(args.outfile, 1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close_pipe(pipefd[1], pipefd[0]);
	execute(args.cmd[args.i], env);
	exit(EXIT_FAILURE);
}

void	child(t_args args, int *pipefd, char **env)
{
	int	fd;

	fd = open_file(args.infile, 0);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close_pipe(pipefd[0], pipefd[1]);
	close(fd);
	execute(args.cmd[args.i], env);
	exit(EXIT_FAILURE);
}

void	pipeline(t_args *args, int *main_pipefd, char **env)
{
	int		new_pipefd[2];
	pid_t	pid;

	while (args->cmd[args->i + 1] != 0)
	{
		pipe(new_pipefd);
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			dup2(main_pipefd[0], STDIN_FILENO);
			dup2(new_pipefd[1], STDOUT_FILENO);
			close_pipe(main_pipefd[0], new_pipefd[1]);
			child(*args, new_pipefd, env);
		}
		waitpid(pid, NULL, 0);
		close_pipe(new_pipefd[1], main_pipefd[0]);
		main_pipefd[0] = new_pipefd[0];
		args->i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	t_args	args;
	t_exit	e;

	e.status = 0;
	e.exit_status = 0;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		args = case_here_doc(argc, argv);
	else
		args = get_args(argc, argv);
	check_args(args, env);
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	main_part(args, pipefd, env, e);
	if (args.is_hd == 1)
		unlink("here_doc");
	free_args(args);
	return (0);
}
