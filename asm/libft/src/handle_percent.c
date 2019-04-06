/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:26:07 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/07 17:26:23 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int		printf_handle_percent(t_str *knot)
{
	size_t size;

	if (knot->r_pad == 0 && knot->zero_pad == 0)
		size = print_width(knot->width, 1, ' ');
	else if (knot->r_pad == 0 && knot->zero_pad == 1)
		size = print_width(knot->width, 1, '0');
	ft_putchar('%');
	if (knot->r_pad == 1)
		size = print_width(knot->width, 1, ' ');
	return (size);
}
