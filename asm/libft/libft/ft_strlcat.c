/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:25:12 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:44:06 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	dlen;
	size_t	slen;

	i = ft_strlen(dst);
	j = 0;
	dlen = i;
	slen = ft_strlen(src);
	if (size < dlen + 1)
		return (slen + size);
	if (size > dlen + 1)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (dlen + slen);
}
