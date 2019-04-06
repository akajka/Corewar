/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:17:54 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:27:03 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	d;

	p = (unsigned char *)s;
	d = (unsigned char)c;
	while (n > 0)
	{
		if (*p == d)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
