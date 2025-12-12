/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:18:53 by nyousfi           #+#    #+#             */
/*   Updated: 2024/11/14 14:19:47 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*assignement(t_list *new, void *(f)(void *), t_list *lst)
{
	new->content = f(lst->content);
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*move;
	t_list	*new;
	t_list	*temp;

	new = malloc(sizeof(t_list));
	if (!lst || !f || !del || !new)
		return (NULL);
	new = assignement(new, f, lst);
	move = new;
	lst = lst->next;
	while (lst)
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp->content = f(lst->content);
		temp->next = NULL;
		move->next = temp;
		move = move->next;
		lst = lst->next;
	}
	return (new);
}
