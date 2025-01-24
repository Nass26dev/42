/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:01:35 by nass              #+#    #+#             */
/*   Updated: 2025/01/24 13:28:48 by nyousfi          ###   ########.fr       */
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

char	*get_cmd_path(int i, char **s_path, char *cmd)
{
	char	*temp;
	char	*cmd_path;

	temp = ft_strjoin(s_path[i], "/");
	if (!temp)
		return (NULL);
	cmd_path = ft_strjoin(temp, cmd);
	if (!cmd_path)
		return (free(temp), NULL);
	free(temp);
	return (cmd_path);
}

char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	**s_path;
	char	*cmd_path;
	int		i;

	path = ft_getenv("PATH", env);
	if (!path)
		return (NULL);
	s_path = ft_split(path, ':');
	if (!s_path)
		return (free(path), NULL);
	i = -1;
	while (s_path[++i])
	{
		cmd_path = get_cmd_path(i, s_path, cmd);
		if (!cmd_path)
			break ;
		if (check_access(cmd_path, s_path))
			return (cmd_path);
		free(cmd_path);
	}
	free_splitted(s_path);
	return (NULL);
}
