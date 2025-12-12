/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:29:12 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/08 12:15:22 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a2;
	int	b2;

	a2 = *a;
	b2 = *b;
	*a = a2 / b2;
	*b = a2 % b2;
}
/*int main()
{
	int a = 10;
	int b = 2;

	ft_ultimate_div_mod(&a,&b);
	if(a == 5 && b == 0)
	{
		printf("Success");
	}
	else
	{
		printf("Fail");
	}
}*/
