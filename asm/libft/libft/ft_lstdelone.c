/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:24:57 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:45:11 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL)
	{
		if (del != NULL)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
