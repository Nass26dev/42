/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:07:14 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/24 12:07:14 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t nb)
{
	ft_memset(src, 0, nb);
}

/*int	main(void)
{
	char	tab[] = "AAAAAAAAAAAAAAAAAAAA";
	int		i = 42;
	ft_bzero(tab, i);
}*/
