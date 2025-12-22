/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:42:47 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/11 17:52:23 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_str_is_alphanum(char str)
{
	if (((str >= 'a') && (str <= 'z'))
		|| ((str >= 'A') && (str <= 'Z'))
		|| ((str >= '0') && (str <= '9')))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	ft_strupcase(char str)
{
	if (('a' <= str) && (str <= 'z'))
		str = str - 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		if (!(ft_str_is_alphanum(str[i - 1])) && ft_str_is_alphanum(str[i]))
			str[i] = ft_strupcase(str[i]);
		i++;
	}
	return (str);
}
/*int     main(void)
{
char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

        printf("%s",ft_strcapitalize(str));
}*/
