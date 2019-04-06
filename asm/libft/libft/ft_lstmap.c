/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:25:17 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:28:52 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *elem;
	t_list *previous;

	if (lst != NULL)
	{
		head = ft_lstnew(lst->content, lst->content_size);
		if (head == NULL)
			return (NULL);
		head = f(head);
		previous = head;
		lst = lst->next;
		while (lst != NULL)
		{
			elem = ft_lstnew(lst->content, lst->content_size);
			if (elem == NULL)
				return (NULL);
			elem = f(elem);
			previous->next = elem;
			lst = lst->next;
			previous = elem;
		}
		return (head);
	}
	return (NULL);
}
