/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 08:30:58 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:34:13 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (src[i])
	{
		i++;
	}
	dest = (char*)malloc(sizeof(*src) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
