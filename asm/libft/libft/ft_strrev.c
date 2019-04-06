/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:09:46 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 18:47:17 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*end;
	char	*rev;
	char	*temp;
	size_t	n;

	n = ft_strlen(s);
	end = s + n - 1;
	rev = ft_strnew(n);
	if (rev == NULL)
		return (NULL);
	temp = rev;
	while (n-- > 0)
		*rev++ = *end--;
	*rev = '\0';
	return (temp);
}
