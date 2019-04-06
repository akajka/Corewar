/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:29:35 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:35:11 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int	printf_handle_str(t_str *knot, va_list *aq)
{
	size_t	str_size;
	char	*str;

	if (knot->length == l)
		return (printf_handle_wstr(knot, aq));
	str = va_arg(*aq, char *);
	if (str == NULL)
		str = "(null)";
	str_size = ft_strlen(str);
	if (knot->got_precision == 1 && str_size > knot->precision)
		str_size = knot->precision;
	else
		knot->precision = str_size;
	if (!knot->r_pad && !knot->zero_pad)
		str_size = print_width(knot->width, str_size, ' ');
	else if (!knot->r_pad && knot->zero_pad)
		str_size = print_width(knot->width, str_size, '0');
	ft_putstrn(str, knot->precision);
	if (knot->width > str_size && knot->r_pad == 1)
		str_size = print_width(knot->width, str_size, ' ');
	return (str_size);
}
