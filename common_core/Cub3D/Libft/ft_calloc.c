/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarion <tmarion@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:18 by tmarion           #+#    #+#             */
/*   Updated: 2024/11/28 14:28:18 by tmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void				*memblok;
	size_t				total;

	total = nb * size;
	if (size != 0 && total / size != nb)
		return (NULL);
	memblok = malloc(total);
	if (!memblok)
		return (NULL);
	ft_memset(memblok, 0, total);
	return (memblok);
}
