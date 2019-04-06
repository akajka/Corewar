/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:12:18 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/24 17:11:24 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *temp;

	temp = dst;
	while (*dst)
		dst++;
	while (n-- && *src)
		*dst++ = *src++;
	*dst++ = '\0';
	return (temp);
}
