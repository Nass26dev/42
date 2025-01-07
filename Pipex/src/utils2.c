/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:14:55 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/07 12:36:12 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipe(int pipe1, int pipe2)
{
	close(pipe1);
	close(pipe2);
}

void	main_part(t_args args, int *pipefd, char **env, t_exit e)
{
	pid_t	pid;

	pid = fork();
	if (pid == CHILD_PID)
		child(args, pipefd, env);
	check_child_success(pid, pipefd, e, args);
	args.i++;
	pipeline(&args, pipefd, env);
	pid = fork();
	if (pid == 0)
		last_child(args, pipefd, env);
}
