/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:56:45 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/28 17:58:41 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	char *sub;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	sub = res;
	if (res == NULL)
		return (NULL);
	while (*s1 != '\0')
		*res++ = *s1++;
	while (*s2 != '\0')
		*res++ = *s2++;
	*res = '\0';
	return (sub);
}
