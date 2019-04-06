/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:12:41 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/21 17:15:05 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if (cdst > csrc)
	{
		cdst += n - 1;
		csrc += n - 1;
		while (n--)
		{
			*cdst-- = *csrc--;
		}
	}
	else
		while (n--)
			*cdst++ = *csrc++;
	return (dst);
}
