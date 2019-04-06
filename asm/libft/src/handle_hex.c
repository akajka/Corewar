/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:51:08 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:44:39 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

void	puthex(uintmax_t nbr, t_str *knot, char c)
{
	if (nbr == 0 && knot->got_precision == 1 && knot->precision == 0)
		return ;
	if (nbr / 16 > 0)
		puthex(nbr / 16, knot, c);
	if (nbr % 16 < 10)
		ft_putchar(nbr % 16 + '0');
	if (nbr % 16 == 10)
		ft_putchar(c == 'X' ? 'A' : 'a');
	if (nbr % 16 == 11)
		ft_putchar(c == 'X' ? 'B' : 'b');
	if (nbr % 16 == 12)
		ft_putchar(c == 'X' ? 'C' : 'c');
	if (nbr % 16 == 13)
		ft_putchar(c == 'X' ? 'D' : 'd');
	if (nbr % 16 == 14)
		ft_putchar(c == 'X' ? 'E' : 'e');
	if (nbr % 16 == 15)
		ft_putchar(c == 'X' ? 'F' : 'f');
}

int		write_hex(char symbol, uintmax_t number, size_t nbr_size, t_str *knot)
{
	size_t str_size;

	str_size = 0;
	if (knot->precision > nbr_size)
		str_size = knot->precision + (knot->hashtag == 1 ? 2 : 0);
	else
		str_size = nbr_size + (knot->hashtag == 1 ? 2 : 0);
	if (knot->hashtag == 1 && knot->zero_pad == 1)
	{
		knot->hashtag = 0;
		ft_putstr(symbol == 'X' ? "0X" : "0x");
	}
	if (str_size < knot->width && knot->r_pad == 0)
		str_size = print_width(knot->width, str_size,
				knot->zero_pad == 1 ? '0' : ' ');
	if (knot->hashtag == 1)
		ft_putstr(symbol == 'X' ? "0X" : "0x");
	nbr_size = print_width(knot->precision, nbr_size, '0');
	puthex(number, knot, symbol);
	if (knot->width > str_size && knot->r_pad == 1)
		str_size = print_width(knot->width, str_size, ' ');
	return (str_size);
}

int		printf_handle_hexa(char c, t_str *knot, va_list *aq)
{
	uintmax_t	nbr;
	size_t		nbr_size;

	nbr = get_unsigned_length(knot, aq);
	if (nbr == 0)
		knot->hashtag = 0;
	if (knot->got_precision == 1)
		knot->zero_pad = 0;
	nbr_size = calc_nbrlen(nbr, 16);
	if (nbr == 0 && knot->got_precision == 1 && knot->precision == 0)
		nbr_size = 0;
	return (write_hex(c, nbr, nbr_size, knot));
}
