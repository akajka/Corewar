/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_arg_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:20:20 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/27 15:20:33 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	write_arg1(int args, int type, int input, int output)
{
	if ((args & 0xc0) == 0x40 && (type == 3 ||
		type == 4 || type == 5 || type == 6 || type == 7 ||
		type == 8 || type == 10 || type == 11 || type == 14 || type == 16))
		return (rewrite_reg(input, output));
	else	if (((args & 0xc0) == 0x80 && (type == 2 || type == 6 ||
		type == 7 ||
		type == 8 || type == 10 || type == 13 || type == 14)) ||
		(type == 1 || type == 9 ||
		type == 12 || type == 15))
		return (rewrite_dir(type, input, output));
	else	if ((args & 0xc0) == 0xc0 && (type == 2 || type == 6 || type == 7 ||
		type == 8 || type == 10 || type == 13 || type == 14))
		return (rewrite_ind(input, output));
	else
		ft_error("Wrong arguments.", 0);
	return (0);
}

int	write_arg2(int args, int type, int input, int output)
{
	if ((args & 0x30) == 0x10 && type != 1 && type != 12 && type != 9
		&& type != 15 && type != 16)
		return (rewrite_reg(input, output));
	else	if ((args & 0x30) == 0x20 && (type == 6 || type == 7 || type == 8
		|| type == 10 || type == 11 || type == 14))
		return (rewrite_dir(type, input, output));
	else	if ((args & 0x30) == 0x30 && (type == 3 || type == 6 ||
		type == 7 || type == 8 || type == 11))
		return (rewrite_ind(input, output));
	else
		ft_error("Wrong arguments.", 0);
	return (0);
}

int	write_arg3(int args, int type, int input, int output)
{
	if ((args & 0xc) == 0x4 && (type == 4 || type == 5 ||
		type == 6 || type == 7 || type == 8 || type == 10 ||
		type == 11 || type == 14))
		return (rewrite_reg(input, output));
	else	if ((args & 0xc) == 0x8 && type == 11)
		return (rewrite_dir(type, input, output));
	else
		ft_error("Wrong arguments.", 0);
	return (0);
}
