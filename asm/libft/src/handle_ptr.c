/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:52:47 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:38:14 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int	printf_handle_ptr(t_str *knot, va_list *aq)
{
	uintmax_t	nbr;
	size_t		nbr_size;

	knot->length = z;
	knot->hashtag = 1;
	nbr = get_unsigned_length(knot, aq);
	if (knot->got_precision == 1)
		knot->zero_pad = 0;
	nbr_size = calc_nbrlen(nbr, 16);
	if (nbr == 0 && knot->got_precision == 1 && knot->precision == 0)
		nbr_size = 0;
	return (write_hex('x', nbr, nbr_size, knot));
}
