/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:58:11 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/10 12:58:13 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int	printf_handle_other(t_str *knot, char c)
{
	int size;

	size = 1;
	if (knot->r_pad == 0)
		size = print_width(knot->width, size, knot->zero_pad == 1 ? '0' : ' ');
	if (c != '\0')
		ft_putchar(c);
	if (knot->r_pad == 1)
		size = print_width(knot->width, size, ' ');
	return (size);
}
