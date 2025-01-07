/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:29:51 by nyousfi           #+#    #+#             */
/*   Updated: 2024/12/23 17:07:28 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while ((unsigned char)s1[i] != '\0' && n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		n--;
	}
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
