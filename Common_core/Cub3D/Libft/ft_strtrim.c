/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:24:36 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/21 18:24:36 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compare(char const *find, char const *tofind, size_t i)
{
	int	y;

	y = 0;
	while (tofind[y])
	{
		if (find[i] == tofind[y])
			return (1);
		y++;
	}
	return (0);
}

static int	ft_check(char const *find, char const *tofind, size_t i)
{
	if (i == 0)
	{
		while (ft_compare(find, tofind, i) == 1)
			i++;
		return (i);
	}
	if (i == ft_strlen(find))
	{
		i--;
		while (ft_compare(find, tofind, i) == 1 && i > 0)
			i--;
		return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*cast;

	start = ft_check(str, set, 0);
	end = ft_check(str, set, ft_strlen(str));
	i = end - start;
	if (end <= 0)
		i = -1;
	if (*str == '\0')
		end--;
	cast = (char *)malloc(sizeof(char) * i + 2);
	if (!cast)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		cast[i] = str[start];
		i++;
		start++;
	}
	cast[i] = '\0';
	return (cast);
}

// int	main(void)
// {
// 	char *str = "  \t \t \n   \n\n\n\t";
// 	char *set = " \t\n";
// 	printf("%s\n", ft_strtrim(str, set));
// }