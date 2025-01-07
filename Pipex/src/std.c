/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:03:12 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/07 12:21:51 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	restore_std(t_error e)
{
	dup2(e.saved_stdin, STDIN_FILENO);
	dup2(e.saved_stdout, STDOUT_FILENO);
	close_pipe(e.saved_stdin, e.saved_stdout);
}
