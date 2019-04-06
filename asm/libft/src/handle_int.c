/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:52:42 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:41:14 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"
#include <stdlib.h>

int		count_nbrstrlen(char *prefix, t_str *knot, uintmax_t nbr)
{
	size_t nbr_size;
	size_t str_size;

	nbr_size = calc_nbrlen(nbr, 10);
	if (nbr == 0 && knot->got_precision == 1 && knot->precision == 0)
		str_size = 0;
	else if (knot->precision > 0)
		str_size = nbr_size > knot->precision ? nbr_size : knot->precision;
	else
		str_size = nbr_size;
	if (prefix != NULL)
		str_size += ft_strlen(prefix);
	return (str_size);
}

void	write_nbr(uintmax_t nbr, unsigned int prec, int flag)
{
	if (nbr == 0 && flag == 1 && prec == 0)
		return ;
	if (nbr / 10 > 0)
		write_nbr(nbr / 10, prec, flag);
	ft_putchar(nbr % 10 + 48);
}

void	ft_putnbr_d(uintmax_t nbr, t_str *knot, size_t *str_len)
{
	size_t			nbr_len;
	unsigned int	prec;

	prec = knot->precision;
	nbr_len = calc_nbrlen(nbr, 10);
	if (knot->precision > nbr_len)
		print_width(knot->precision, nbr_len, '0');
	write_nbr(nbr, prec, knot->got_precision);
	if (knot->width > 0 && knot->r_pad == 1)
		*str_len = print_width(knot->width, *str_len, ' ');
}

int		print_intmax(char *p, t_str *knot, uintmax_t nbr)
{
	size_t size;

	size = count_nbrstrlen(p, knot, nbr);
	if (knot->width > size && !knot->r_pad && !knot->zero_pad)
		size = print_width(knot->width, size, ' ');
	if (knot->width > 0 && knot->zero_pad == 1)
	{
		if (p != NULL && knot->width - size > 0)
		{
			ft_putstr(p);
			p = NULL;
		}
		if (knot->width > size)
			size = print_width(knot->width, size, '0');
	}
	if (p != NULL && *p != '\0')
		ft_putstr(p);
	ft_putnbr_d(nbr, knot, &size);
	return (size);
}

int		printf_handle_int(t_str *knot, va_list *aq)
{
	intmax_t	nbr;
	char		*prefix;

	prefix = NULL;
	nbr = get_int_length(knot, aq);
	if (knot->got_precision == 1)
		knot->zero_pad = 0;
	if (knot->sign == 1 && nbr >= 0)
		prefix = "+";
	else if (knot->space == 1 && nbr < 0)
	{
		nbr *= -1;
		prefix = "-";
	}
	else if (knot->space == 1)
		prefix = " ";
	else if (nbr < 0)
	{
		nbr *= -1;
		prefix = "-";
	}
	return (print_intmax(prefix, knot, nbr));
}
