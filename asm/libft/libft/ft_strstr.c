/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:44:36 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/24 17:33:28 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *str;
	const char *need;

	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		str = s1;
		need = s2;
		while (*need && *str == *need)
		{
			need++;
			str++;
		}
		if (*need == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
