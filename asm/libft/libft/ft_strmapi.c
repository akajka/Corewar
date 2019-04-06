/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:06:13 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:44:27 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	res = ft_strnew(ft_strlen(s));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
