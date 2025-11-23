/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:19:47 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/23 02:19:47 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*str;

	y = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	while (s1[y])
	{
		str[y] = s1[y];
		y++;
	}
	while (s2[i])
	{
		str[y] = s2[i];
		i++;
		y++;
	}
	str[y] = 0;
	free((char *)s1);
	return (str);
}

/*int	main(void)
{
	//int	i = 258;
	//int	j =5;
	char s1[] = "";
	char s2[] = "";

	printf("ft_: %s\n", ft_strjoin(s1, s2));
	//printf("original: %s\n",strjoin(s1, s2));
}*/