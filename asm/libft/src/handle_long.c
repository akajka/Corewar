/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:52:01 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:39:03 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int	printf_handle_long(char **c, t_str *knot, va_list *aq)
{
	knot->length = l;
	if (**c == 'D')
		return (printf_handle_int(knot, aq));
	if (**c == 'O')
		return (printf_handle_octal(knot, aq));
	else
		return (printf_handle_udint(knot, aq));
}
