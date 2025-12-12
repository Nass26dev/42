/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:58:34 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/22 11:10:41 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	ft_sort_params(char **str, int size)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < (size - 1))
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			temp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	argv++;
	ft_sort_params(argv, argc - 1);
	while (i < (argc - 1))
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
