/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:24:04 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/16 13:59:08 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*add_num(int i)
{
	char	*temp;
	char	*filename;

	temp = ft_itoa(i);
	if (!temp)
		return (NULL);
	filename = ft_strjoin(BASE_FILENAME, temp);
	free(temp);
	return (filename);
}

char	*create_file(void)
{
	int		fd;
	char	*filename;
	int		i;

	i = 1;
	while (i <= MAX_TRIES)
	{
		if (i == 1)
			filename = ft_strdup(BASE_FILENAME);
		else
			filename = add_num(i);
		if (!filename)
			return (NULL);
		fd = open(filename, O_CREAT | O_EXCL, 0777);
		if (fd != -1)
		{
			close(fd);
			return (filename);
		}
		i++;
		free(filename);
	}
	write(STDERR_FILENO, "impossible to create tmp file", 29);
	exit(EXIT_FAILURE);
}

char	*create_hd(char **argv)
{
	int		fd;
	char	*str;
	char	*filename;

	filename = create_file();
	fd = open(filename, O_WRONLY, 0777);
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
	return (filename);
}

t_args	case_here_doc(int argc, char **argv)
{
	int		i;
	int		j;
	char	*filename;
	t_args	args;

	args.is_hd = 1;
	args.cmd = malloc((argc - 3) * sizeof(char *));
	i = 3;
	j = 0;
	while (i < argc - 1)
		args.cmd[j++] = ft_strdup(argv[i++]);
	args.cmd[j] = NULL;
	filename = create_hd(argv);
	if (!filename)
	{
		free_args(args);
		exit(EXIT_FAILURE);
	}
	args.infile = ft_strdup(filename);
	free(filename);
	args.outfile = ft_strdup(argv[argc - 1]);
	args.i = 0;
	return (args);
}
