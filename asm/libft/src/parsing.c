/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:38:29 by ystasiv           #+#    #+#             */
/*   Updated: 2018/07/28 15:44:51 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

char	*parse_flags(char **str, t_str *knot)
{
	if (**str == ' ' || **str == '+' || **str == '-' ||
		**str == '0' || **str == '#')
	{
		if (**str == '#')
			knot->hashtag = 1;
		else if (**str == '0')
			knot->zero_pad = 1;
		else if (**str == ' ')
			knot->space = 1;
		else if (**str == '-')
			knot->r_pad = 1;
		else if (**str == '+')
			knot->sign = 1;
		(*str)++;
		if (knot->r_pad == 1)
			knot->zero_pad = 0;
		return (parse_flags(str, knot));
	}
	else
		return (*str);
}

char	*parse_width(char **str, t_str *knot, va_list *aq)
{
	int w;

	w = 0;
	if (**str == '*' || ft_isdigit(**str))
	{
		if (**str == '*')
		{
			w = va_arg(*aq, int);
			(*str)++;
		}
		else if (ft_isdigit(**str))
		{
			w = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		if (w < 0)
		{
			knot->r_pad = 1;
			knot->zero_pad = 0;
			w *= -1;
		}
		knot->width = w;
	}
	return (*str);
}

char	*parse_precision(char **str, t_str *knot, va_list *aq)
{
	int p;

	p = 0;
	if (**str == '.')
	{
		while (**str == '.')
			(*str)++;
		if (**str == '*')
		{
			(*str)++;
			p = va_arg(*aq, int);
			p = p > 0 ? p : -p;
		}
		else if (ft_isdigit(**str))
		{
			p = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		knot->got_precision = 1;
		knot->precision = (unsigned int)p;
	}
	return (*str);
}

char	*parse_lenght(char **str, t_str *knot)
{
	if (**str == 'h' && *(*str + 1) == 'h')
	{
		knot->length = hh;
		return (*str += 2);
	}
	else if (**str == 'l' && *(*str + 1) == 'l')
	{
		knot->length = ll;
		return (*str += 2);
	}
	if (**str == 'h' || **str == 'l' || **str == 'j' ||
		**str == 'z')
	{
		if (**str == 'h')
			knot->length = h;
		else if (**str == 'l')
			knot->length = l;
		else if (**str == 'j')
			knot->length = j;
		else if (**str == 'z')
			knot->length = z;
		return ((*str)++);
	}
	return (*str);
}
