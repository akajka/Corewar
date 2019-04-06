/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:59:18 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:34:36 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

size_t	ft_wstrlen(wchar_t *str, int *bytes)
{
	size_t res;

	res = 0;
	while (*str != '\0')
	{
		if (*str <= 0x7F)
			res++;
		else if (*str <= 0x7FF)
		{
			*bytes = 2;
			res += 2;
		}
		else if (*str <= 0x7FFFF)
		{
			res += 3;
			*bytes = 3;
		}
		else if (*str <= 0x7FFFFF)
		{
			*bytes = 1;
			res += 4;
		}
		str++;
	}
	return (res);
}

void	ft_putwstrn(wchar_t *str, int n)
{
	while (*str && n > 0)
	{
		if (*str <= 0x7F)
			n--;
		else if (*str <= 0x7FF)
			n -= 2;
		else if (*str <= 0x7FFFF)
			n -= 3;
		else if (*str <= 0x7FFFFF)
			n -= 4;
		ft_putwchar(*str);
		str++;
	}
}

int		printf_handle_wstr(t_str *knot, va_list *aq)
{
	wchar_t	*str;
	size_t	str_len;
	int		bytes;

	bytes = 1;
	str = va_arg(*aq, wchar_t *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	str_len = ft_wstrlen(str, &bytes);
	while (knot->precision % bytes != 0)
		knot->precision--;
	if (knot->got_precision == 1)
		str_len = knot->precision;
	else
		knot->precision = str_len;
	if (knot->r_pad == 0)
		str_len = print_width(knot->width,
				knot->precision, knot->zero_pad == 1 ? '0' : ' ');
	ft_putwstrn(str, knot->precision);
	if (knot->r_pad == 1)
		str_len = print_width(knot->width, str_len, ' ');
	return (str_len);
}
