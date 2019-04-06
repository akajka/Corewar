/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:34:09 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/27 17:05:46 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	int		cmp;

	if (*needle == '\0')
		return ((char *)haystack);
	c = ft_strlen(needle);
	cmp = 1;
	while (*haystack != '\0' && c <= len
			&& (cmp = ft_strncmp(haystack, needle, c)))
	{
		haystack++;
		len--;
	}
	if (cmp == 0)
		return ((char *)haystack);
	return (0);
}
