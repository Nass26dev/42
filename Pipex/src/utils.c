/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:01:35 by nass              #+#    #+#             */
/*   Updated: 2025/01/14 17:55:05 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_file(char *name, int boolean)
{
	int	fd;

	fd = -1;
	if (boolean == 0)
		fd = open(name, O_RDONLY, 0777);
	else if (boolean == 1)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (boolean == 2)
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*ft_getenv(char *search, char **env)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(search);
	while (env[++i])
	{
		if (ft_strncmp(env[i], search, len) == 0 && env[i][len] == '=')
			return (env[i] + (len + 1));
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

char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	**s_path;
	char	*cmd_path;
	char	*temp;
	int		i;

	path = ft_getenv("PATH", env);
	s_path = ft_split(path, ':');
	i = -1;
	while (s_path[++i])
	{
		temp = ft_strjoin(s_path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_splitted(s_path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_splitted(s_path);
	return (NULL);
}

t_args	get_args(int argc, char **argv)
{
	int		i;
	int		j;
	t_args	args;

	args.is_hd = 0;
	args.cmd = malloc((argc - 2) * sizeof(char *));
	i = 2;
	j = 0;
	while (i < argc - 1)
		args.cmd[j++] = ft_strdup(argv[i++]);
	args.cmd[j] = NULL;
	args.infile = ft_strdup(argv[1]);
	args.outfile = ft_strdup(argv[argc - 1]);
	args.i = 0;
	return (args);
}
