/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:44:42 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/24 13:39:38 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
