/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lenght.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:56:42 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/07 13:56:45 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

intmax_t	get_int_length(t_str *knot, va_list *aq)
{
	intmax_t nbr;

	nbr = va_arg(*aq, intmax_t);
	if (knot->length == hh)
		nbr = (char)nbr;
	else if (knot->length == h)
		nbr = (short)nbr;
	else if (knot->length == l)
		nbr = (long)nbr;
	else if (knot->length == ll)
		nbr = (long long)nbr;
	else if (knot->length == j)
		nbr = (intmax_t)nbr;
	else if (knot->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	get_unsigned_length(t_str *knot, va_list *aq)
{
	uintmax_t nbr;

	nbr = va_arg(*aq, uintmax_t);
	if (knot->length == hh)
		nbr = (unsigned char)nbr;
	else if (knot->length == h)
		nbr = (unsigned short int)nbr;
	else if (knot->length == ll)
		nbr = (unsigned long long int)nbr;
	else if (knot->length == l)
		nbr = (unsigned long int)nbr;
	else if (knot->length == j)
		nbr = (uintmax_t)nbr;
	else if (knot->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
