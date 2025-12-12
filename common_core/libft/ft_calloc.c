/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:42:05 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/14 14:23:24 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	unsigned char	*ptr;

	if (element_size != 0)
	{
		if (num_elements > (SIZE_MAX / element_size))
			return (NULL);
	}
	ptr = malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (num_elements * element_size));
	return ((void *)ptr);
}
