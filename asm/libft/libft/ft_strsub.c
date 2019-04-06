/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:44:36 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:25:57 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	sub = ft_strnew(len);
	if (sub == NULL)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		sub[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (sub);
}
