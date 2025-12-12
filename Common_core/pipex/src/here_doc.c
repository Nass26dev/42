/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:24:04 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 14:40:18 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*recup_filename(t_args args)
{
	char	*filename;

	filename = create_file();
	if (!filename)
	{
		free_args(args);
		exit(EXIT_FAILURE);
	}
	return (filename);
}

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

char	*read_std(char **argv, t_args args)
{
	int		fd;
	char	*str;
	char	*filename;

	filename = recup_filename(args);
	fd = open(filename, O_WRONLY, 0777);
	if (fd == -1)
	{
		free(filename);
		free_args(args);
		perror("open temp file error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0
			&& (ft_strlen(str) - 1) == ft_strlen(argv[2]))
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
	}
	close(fd);
	return (free(str), filename);
}

t_args	case_here_doc(int argc, char **argv)
{
	char	*filename;
	t_args	args;

	init_args(&args);
	args.is_hd = 1;
	args.cmd = malloc((argc - 3) * sizeof(char *));
	if (!args.cmd)
		exit(EXIT_FAILURE);
	allocate_cmd(3, argc, argv, args);
	filename = read_std(argv, args);
	if (!filename)
	{
		free_args(args);
		exit(EXIT_FAILURE);
	}
	init_in_out(&args, filename, argv, argc);
	free(filename);
	args.i = 0;
	return (args);
}
