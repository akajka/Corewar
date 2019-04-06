/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:00:03 by ystasiv           #+#    #+#             */
/*   Updated: 2018/07/30 19:22:14 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int	printf_handle_char(t_str *knot, va_list *aq)
{
	size_t size;

	size = 1;
	if (knot->length == l)
		return (printf_handle_wchar(knot, aq));
	else
	{
		if (knot->r_pad == 0)
			size = print_width(knot->width, size,
				knot->zero_pad == 1 ? '0' : ' ');
		ft_putchar(va_arg(*aq, int));
		if (knot->width > 0 && knot->r_pad == 1)
			size = print_width(knot->width, size, ' ');
	}
	return (size);
}
