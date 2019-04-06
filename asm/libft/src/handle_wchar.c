/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:11:18 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:36:33 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"
#include <stdint.h>

void	ft_putwchar(wchar_t s)
{
	if (s <= 0x7F)
		ft_putchar(s);
	else if (s <= 0x7FF)
	{
		ft_putchar((s >> 6) + 0xC0);
		ft_putchar((s & 0x3F) + 0x80);
	}
	else if (s <= 0x7FFFF)
	{
		ft_putchar((s >> 12) + 0xE0);
		ft_putchar(((s >> 6) & 0x3F) + 0x80);
		ft_putchar((s & 0x3F) + 0x80);
	}
	else if (s <= 0x7FFFFF)
	{
		ft_putchar((s >> 18) + 0xF0);
		ft_putchar(((s >> 12) & 0x3F) + 0x80);
		ft_putchar(((s >> 6) & 0x3F) + 0x80);
		ft_putchar((s & 0x3F) + 0x80);
	}
}

int		printf_handle_wchar(t_str *knot, va_list *aq)
{
	size_t	len;
	wchar_t	symb;

	symb = va_arg(*aq, wint_t);
	if (symb <= 0x7F)
		len = 1;
	else if (symb <= 0x7FF)
		len = 2;
	else if (symb <= 0x7FFFF)
		len = 3;
	else if (symb <= 0x7FFFFF)
		len = 4;
	else
		len = 0;
	if (knot->width > len && knot->r_pad == 0)
		len = print_width(knot->width, len, ' ');
	ft_putwchar(symb);
	if (knot->width > len && knot->r_pad == 1)
		len = print_width(knot->width, len, ' ');
	return (len);
}
