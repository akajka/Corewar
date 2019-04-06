/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:39:59 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:46:13 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *res;
	char *temp;

	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (res == NULL)
		return (NULL);
	temp = res;
	while (*s != '\0')
	{
		*res = f(*s);
		s++;
		res++;
	}
	*res = '\0';
	return (temp);
}
