/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:52:11 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/27 16:18:50 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *one;
	unsigned char *two;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (n--)
	{
		if (*one == *two)
		{
			one++;
			two++;
		}
		else
			return (*one - *two);
	}
	return (0);
}
