/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:57:59 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/14 13:54:06 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while (s1[i] != '\0' && s2[i] != '\0' && n != 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
		n--;
	}
	return (s1[i] - s2[i]);
}

/*int main()
{
	char s1[] = "aba";
	char s2[] = "aba";

	printf("%d\n",ft_strncmp(s1,s2,5));
	printf("%d",strncmp(s1,s2,5));
}*/
