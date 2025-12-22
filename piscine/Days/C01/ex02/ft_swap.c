/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:44:51 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/07 16:09:09 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int main(void)
{
	int a = 5;
	int b = 7;
	ft_swap(&a, &b);

	if (a == 7 && b == 5)
	{
		printf("Success");
	}
	else
	{
		printf("Fail");
	}
}*/
