/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:59:36 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/07 13:59:40 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

size_t	calc_nbrlen(uintmax_t nbr, int base)
{
	size_t res;

	res = 0;
	if (nbr == 0)
		res = 1;
	while (nbr != 0)
	{
		nbr /= base;
		res++;
	}
	return (res);
}

size_t	print_width(unsigned int wight, unsigned int size, char c)
{
	while (wight > size)
	{
		ft_putchar(c);
		size++;
	}
	return (size);
}
