/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:15:17 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 14:41:58 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	allocate_cmd(int i, int argc, char **argv, t_args args)
{
	int	j;

	j = 0;
	while (i < argc - 1)
	{
		args.cmd[j] = ft_strdup(argv[i++]);
		if (!args.cmd[j])
		{
			free_args(args);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	args.cmd[j] = NULL;
}

void	init_in_out(t_args *args, char *infile, char **argv, int argc)
{
	args->infile = ft_strdup(infile);
	args->outfile = ft_strdup(argv[argc - 1]);
	if (!args->infile || !args->outfile)
	{
		if (args->is_hd)
		{
			unlink(infile);
			free(infile);
		}
		free_args(*args);
		exit(EXIT_FAILURE);
	}
}

void	init_args(t_args *args)
{
	args->cmd = NULL;
	args->infile = NULL;
	args->outfile = NULL;
	args->stopper = NULL;
}

t_args	get_args(int argc, char **argv)
{
	t_args	args;

	init_args(&args);
	args.is_hd = 0;
	args.cmd = malloc((argc - 2) * sizeof(char *));
	if (!args.cmd)
		exit(EXIT_FAILURE);
	allocate_cmd(2, argc, argv, args);
	init_in_out(&args, argv[1], argv, argc);
	args.i = 0;
	return (args);
}
