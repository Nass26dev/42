/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:46:20 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/08 11:00:59 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

/*void  affichage(int *tab,int size)
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
int     main()
{
        int tab[] = {9,3,6,1,4,6,2};
        int size = sizeof(tab) / sizeof(tab[0]);

        affichage(tab,size);
        printf("\n");
        ft_sort_int_tab(tab,size);
        affichage(tab,size);
}*/
