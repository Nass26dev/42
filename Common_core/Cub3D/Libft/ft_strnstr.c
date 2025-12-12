/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft0_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:29:43 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/22 21:29:43 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *find, const char *tofind, int i)
{
	int	y;

	y = 0;
	while (find[i] == tofind[y] && tofind[y])
	{
		i++;
		y++;
	}
	if (y == (int)ft_strlen(tofind))
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *find, const char *tofind, size_t n)
{
	size_t	i;

	i = 0;
	if (!*tofind && !*find)
		return ((char *)find);
	if (!*find)
		return (NULL);
	if (!*tofind)
		return ((char *)find);
	while (i <= n)
	{
		if (find[i] == tofind[0])
			if (ft_check(find, tofind, i) == 1 && (ft_strlen(tofind)
					+ i) <= n)
				return ((char *)find + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s1[] = "01ab2abc3abcd456789";
// 	//			 0123456789012345678
// 	char s2[] = "";
// 	int	i = -1;
// 	printf("%s\n", ft_strnstr(s1, s2, i));
// }