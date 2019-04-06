/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:28:34 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:51:05 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if ((ft_strchr(s, c)) == NULL)
		return (NULL);
	while (*s != '\0')
		s++;
	while (*s != (char)c)
		s--;
	return ((char*)s);
}
