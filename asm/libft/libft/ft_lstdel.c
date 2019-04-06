/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:39:08 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:22:15 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *list;

	if (*alst != NULL && del != NULL)
	{
		list = *alst;
		next = *alst;
		while (list != NULL)
		{
			next = next->next;
			ft_lstdelone(&list, del);
			list = next;
		}
		*alst = NULL;
	}
}
