/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:41:46 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:26:08 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countsymb(int n)
{
	int x;

	x = 0;
	if (n == 0)
		x++;
	else if (n == -2147483648)
		x = 11;
	else
	{
		if (n < 0)
			x++;
		while (n != 0)
		{
			x++;
			n = n / 10;
		}
	}
	return (x);
}

char		*ft_itoa(int n)
{
	char			*str;
	char			*temp;
	unsigned int	t;

	str = ft_strnew(countsymb(n));
	if (str == NULL)
		return (NULL);
	temp = str;
	t = n;
	if (n < 0)
		t = -n;
	if (t == 0)
		*str++ = '0';
	while (t > 0)
	{
		*str++ = t % 10 + '0';
		t = t / 10;
	}
	if (n < 0)
		*str++ = '-';
	*str = '\0';
	str = ft_strrev(temp);
	return (str);
}
