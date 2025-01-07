/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:24:04 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/07 10:40:53 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	create_hd(char **argv)
{
	int		fd;
	char	*str;

	fd = open("here_doc", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		perror("open temp file error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			exit(EXIT_FAILURE);
		else if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
	}
	free(str);
	close(fd);
}

t_args	case_here_doc(int argc, char **argv)
{
	int		i;
	int		j;
	t_args	args;

	args.is_hd = 1;
	args.cmd = malloc((argc - 3) * sizeof(char *));
	i = 3;
	j = 0;
	while (i < argc - 1)
		args.cmd[j++] = ft_strdup(argv[i++]);
	args.cmd[j] = NULL;
	create_hd(argv);
	args.infile = ft_strdup("here_doc");
	args.outfile = ft_strdup(argv[argc - 1]);
	args.i = 0;
	return (args);
}
