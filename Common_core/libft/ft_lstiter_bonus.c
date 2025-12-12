/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:16:08 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/08 15:21:09 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))

{
	t_list	*move;

	if (!f || !lst)
		return ;
	move = lst;
	while (move->next)
	{
		f(move->content);
		move = move->next;
	}
	f(move->content);
}
