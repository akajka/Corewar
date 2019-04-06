/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:06:47 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/01 11:06:53 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int	printf_handle_udint(t_str *knot, va_list *aq)
{
	uintmax_t nbr;

	nbr = get_unsigned_length(knot, aq);
	if (knot->got_precision == 1)
		knot->zero_pad = 0;
	return (print_intmax(NULL, knot, nbr));
}
