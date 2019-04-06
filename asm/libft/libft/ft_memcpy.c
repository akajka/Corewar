/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:10:51 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/28 16:28:40 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	cdst = (char*)dst;
	csrc = (char*)src;
	while (n--)
	{
		*cdst++ = *csrc++;
	}
	return (dst);
}
