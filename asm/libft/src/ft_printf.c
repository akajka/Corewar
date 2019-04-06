/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:31:11 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:46:20 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hand.h"

int		get_handler(char **c, t_str *knot, va_list *aq)
{
	if (**c == '%')
		return (printf_handle_percent(knot));
	if (**c == 'd' || **c == 'i')
		return (printf_handle_int(knot, aq));
	else if (**c == 'c')
		return (printf_handle_char(knot, aq));
	else if (**c == 's')
		return (printf_handle_str(knot, aq));
	else if (**c == 'o')
		return (printf_handle_octal(knot, aq));
	else if (**c == 'D' || **c == 'O' || **c == 'U')
		return (printf_handle_long(c, knot, aq));
	else if (**c == 'u')
		return (printf_handle_udint(knot, aq));
	else if (**c == 'x' || **c == 'X')
		return (printf_handle_hexa(**c, knot, aq));
	else if (**c == 'p')
		return (printf_handle_ptr(knot, aq));
	else if (**c == 'C')
		return (printf_handle_wchar(knot, aq));
	else if (**c == 'S')
		return (printf_handle_wstr(knot, aq));
	else
		return (printf_handle_other(knot, **c));
}

int		handle_spec(char **str, t_str *knot, va_list *aq)
{
	int res;

	if (*(++*str) == '\0')
		return (0);
	if (!parse_flags(str, knot) ||
			!parse_width(str, knot, aq) ||
			!parse_precision(str, knot, aq) ||
			!parse_lenght(str, knot))
		return (-1);
	if (**str == '\0')
		return (0);
	res = get_handler(str, knot, aq);
	(*str)++;
	return (res);
}

int		handle_str(char *str, va_list *aq, size_t size)
{
	t_str	knot;
	int		s;
	char	*next_arg;

	next_arg = ft_strchr(str, '%');
	if (*str == '\0')
		return (size);
	if (next_arg == NULL)
	{
		ft_putstr(str);
		return (ft_strlen(str) + size);
	}
	if (next_arg > str)
	{
		ft_putstrn(str, next_arg - str);
		return (handle_str(next_arg, aq, size + next_arg - str));
	}
	else
	{
		ft_bzero(&knot, sizeof(t_str));
		if ((s = handle_spec(&next_arg, &knot, aq)) == -1)
			return (-1);
		else
			return (handle_str(next_arg, aq, size + (size_t)s));
	}
}

int		ft_printf(const char *str, ...)
{
	int		res;
	va_list	aq;

	va_start(aq, str);
	res = handle_str((char *)str, &aq, 0);
	va_end(aq);
	return (res);
}
