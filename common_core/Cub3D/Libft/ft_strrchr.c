/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:39:33 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/27 00:39:33 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *find, int tofind)
{
	int	i;

	i = 0;
	tofind = (unsigned char)tofind;
	if (tofind > 127)
		return ((char *)find);
	while (i <= (int)ft_strlen(find))
		i++;
	i--;
	while (i >= 0)
	{
		if (find[i] == tofind)
			return ((char *)find + i);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char src[] = "132456789";

	printf("%s", ft_strrchr(src, 52));
	return (0);
}*/