/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:20:44 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/27 18:09:43 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char *p;

	p = memptr;
	while (num)
	{
		*p = (unsigned char)val;
		p++;
		num--;
	}
	return (memptr);
}
