/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:03:28 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/08 10:42:24 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	debut;
	int	fin;
	int	temp;

	debut = 0;
	fin = size - 1;
	while (debut < fin)
	{
		temp = tab[debut];
		tab[debut] = tab[fin];
		tab[fin] = temp;
		debut++;
		fin--;
	}
}

/*void	affichage(int *tab,int size)
{
	int i = 0;
	int temp;
	
	while (i < size)
	{
		temp = tab[i];
		printf("%d", temp);
		i++;
	}
}
int	main()
{
	int tab[] = {1,2,3,4,5};
	int size = sizeof(tab) / sizeof(tab[0]);

	affichage(tab,size);
	printf("\n");
	ft_rev_int_tab(tab,size);
	affichage(tab,size);
}*/
