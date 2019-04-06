/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:21:14 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:45:08 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

void	write_nbr8(uintmax_t nbr, t_str *knot)
{
	if (nbr == 0 && knot->got_precision == 1)
		return ;
	if (nbr / 8 > 0)
		write_nbr8(nbr / 8, knot);
	ft_putchar(nbr % 8 + 48);
}

int		write_octal(uintmax_t number, size_t nbr_size, t_str *knot)
{
	size_t str_size;

	if (knot->precision > nbr_size)
		str_size = knot->precision;
	else
		str_size = nbr_size;
	if (str_size < knot->width && knot->r_pad == 0)
		str_size = print_width(knot->width, str_size,
			knot->zero_pad == 1 ? '0' : ' ');
	if (knot->precision > nbr_size)
		nbr_size = print_width(knot->precision, nbr_size, '0');
	write_nbr8(number, knot);
	if (knot->width > str_size && knot->r_pad == 1)
		str_size = print_width(knot->width, str_size, ' ');
	return (str_size);
}

int		printf_handle_octal(t_str *knot, va_list *aq)
{
	uintmax_t	nbr;
	size_t		nbr_size;

	nbr = get_unsigned_length(knot, aq);
	if (knot->got_precision == 1)
		knot->zero_pad = 0;
	nbr_size = calc_nbrlen(nbr, 8);
	if (nbr == 0 && knot->got_precision == 0)
		knot->hashtag = 0;
	if (nbr == 0 && knot->got_precision == 1 && knot->precision == 0)
		nbr_size = 0;
	if (knot->precision <= nbr_size && knot->hashtag == 1)
		knot->precision = nbr_size + 1;
	return (write_octal(nbr, nbr_size, knot));
}
