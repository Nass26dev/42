/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:37:12 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 14:37:36 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
