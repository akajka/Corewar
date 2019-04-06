/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:59:07 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/24 17:10:28 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dstptr, const char *srcptr)
{
	char	*temp;

	temp = dstptr;
	while (*dstptr != '\0')
		dstptr++;
	while (*srcptr)
		*dstptr++ = *srcptr++;
	*dstptr = '\0';
	return (temp);
}
