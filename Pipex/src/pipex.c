/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:47:26 by nass              #+#    #+#             */
/*   Updated: 2025/01/24 11:41:06 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	if (ft_strlen(cmd) == 0)
	{
		ft_putstr_fd("cmd empty\n", STDERR_FILENO);
		return ;
	}
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		return ;
	path = find_path(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("cmd not found : ", STDERR_FILENO);
		ft_putendl_fd(cmd, STDERR_FILENO);
		free_splitted(s_cmd);
		return ;
	}
	execve(path, s_cmd, env);
	perror("execve failed");
	free_splitted(s_cmd);
	free(path);
}

void	pipex(int rd, int wr, t_args args, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		if (args.is_hd)
			unlink(args.infile);
		free_args(args);
		close_pipes(rd, wr);
		exit(EXIT_FAILURE);
	}
	if (pid == CHILD_PID)
	{
		dup2(rd, STDIN_FILENO);
		dup2(wr, STDOUT_FILENO);
		close_pipes(rd, wr);
		execute(args.cmd[args.i], env);
		free_args(args);
		exit(EXIT_FAILURE);
	}
	check_child_success(pid, rd, wr, args);
}

void	first_and_last_child(t_utils u, t_args args, char **env)
{
	if (u.j == 0)
		u.fd = open_file(args.infile, 0);
	else if (args.is_hd == 1)
		u.fd = open_file(args.outfile, 2);
	else
		u.fd = open_file(args.outfile, 1);
	if (u.fd == -1)
	{
		free_args(args);
		perror("open error");
		exit(EXIT_FAILURE);
	}
	if (u.j == 0)
		pipex(u.fd, u.pipefd[1], args, env);
	else
		pipex(u.last_rd, u.fd, args, env);
	close(u.fd);
}

void	main_loop(t_utils u, t_args args, char **env)
{
	while (args.cmd[args.i] != 0)
	{
		if (u.j != u.i)
			pipe(u.pipefd);
		if (u.j == 0)
			first_and_last_child(u, args, env);
		else if (u.j != u.i - 1)
			pipex(u.last_rd, u.pipefd[1], args, env);
		else
			first_and_last_child(u, args, env);
		if (u.j != 0)
			close(u.last_rd);
		u.last_rd = dup(u.pipefd[0]);
		close_pipes(u.pipefd[0], u.pipefd[1]);
		args.i++;
		u.j++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_args	args;
	t_utils	u;

	if (argc < 5 || (argc < 6 && ft_strncmp(argv[1], "here_doc",
				ft_strlen("here_doc")) == 0
			&& ft_strlen(argv[1]) == ft_strlen("here_doc")))
	{
		write(2, "wrong format\n", 13);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0
		&& ft_strlen(argv[1]) == ft_strlen("here_doc"))
		args = case_here_doc(argc, argv);
	else
		args = get_args(argc, argv);
	u.i = 0;
	u.j = 0;
	while (args.cmd[u.i])
		u.i++;
	main_loop(u, args, env);
	if (args.is_hd == 1)
		unlink(args.infile);
	free_args(args);
	return (0);
}
