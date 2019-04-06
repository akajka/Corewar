/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:51:16 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:26:49 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*cdst;
	const char	*csrc;
	char		s;

	cdst = (char*)dst;
	csrc = (char*)src;
	s = (char)c;
	while (n > 0 && *csrc != s)
	{
		n--;
		*cdst++ = *csrc++;
	}
	if (n > 0)
	{
		*cdst++ = *csrc++;
		return ((void*)cdst);
	}
	else
		return (NULL);
}
