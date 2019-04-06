/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:58:48 by ystasiv           #+#    #+#             */
/*   Updated: 2018/08/11 11:04:18 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_H
# define HAND_H

# include <stdarg.h>
# include "ft_printf.h"
# include <stdio.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <wchar.h>

typedef struct		s_str
{
	enum
	{
		none, hh, h, ll, l, j, z
	}				length;
	int				hashtag;
	int				zero_pad;
	int				space;
	int				sign;
	int				r_pad;
	int				got_precision;
	unsigned int	width;
	unsigned int	precision;
}					t_str;

char				*parse_flags(char **str, t_str *knot);
char				*parse_width(char **str, t_str *knot, va_list *aq);
char				*parse_precision(char **str, t_str *knot, va_list *aq);
char				*parse_lenght(char **str, t_str *knot);
int					printf_handle_int(t_str *knot, va_list *aq);
int					printf_handle_char(t_str *knot, va_list *aq);
int					printf_handle_wchar(t_str *knot, va_list *aq);
int					printf_handle_wstr(t_str *knot, va_list *aq);
int					printf_handle_percent(t_str *knot);
int					printf_handle_long(char **c, t_str *knot, va_list *aq);
int					printf_handle_str(t_str *knot, va_list *aq);
int					printf_handle_udint(t_str *knot, va_list *aq);
int					printf_handle_octal(t_str *knot, va_list *aq);
int					printf_handle_hexa(char c, t_str *knor, va_list *aq);
int					printf_handle_other(t_str *knot, char c);
int					printf_handle_ptr(t_str *knot, va_list *aq);
int					get_handler(char **c, t_str *knot, va_list *aq);
uintmax_t			get_unsigned_length(t_str *knot, va_list *aq);
void				ft_putwchar(wchar_t s);
int					print_intmax(char *p, t_str *knot, uintmax_t nbr);
intmax_t			get_int_length(t_str *knot, va_list *aq);
size_t				calc_nbrlen(uintmax_t nbr, int base);
size_t				print_width(unsigned int width, unsigned int size, char c);
int					write_hex(char s, uintmax_t numb, size_t n, t_str *k);
#endif
