/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:57:08 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/24 17:02:22 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *t;

	t = malloc(size);
	if (t == NULL)
		return (NULL);
	else
		return (ft_memset(t, 0, size));
}
