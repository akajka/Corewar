/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:22:17 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/27 15:22:47 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_writenbr(int fd, int n)
{
	char c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n / 10 > 0)
			ft_writenbr(fd, n / 10);
		c = n % 10 + 48;
		write(fd, &c, 1);
	}
}

int		rewrite_dir(int ty, int in, int out)
{
	int size;
	int dir;

	dir = 0;
	if (ty == 1 || ty == 2 || ty == 13 || ty == 6 || ty == 7 || ty == 8)
		size = 4;
	else
		size = 2;
	write(out, "%", 1);
	read(in, &dir, size);
	if (size == 2)
		dir = ((dir >> 8) & 0xff) | ((dir << 8) & 0xff00);
	else
		dir = ((dir >> 24) & 0xff) | ((dir & 0xff0000) >> 8) |
		((dir & 0xff00) << 8) | ((dir << 24) & 0xff000000);
	if (dir > 32767 && size == 2)
		dir = -1 * (65535 - dir + 1);
	else if (dir > 2147483647 && size == 4)
		dir = -1 * (4294967295 - dir + 1);
	ft_writenbr(out, dir);
	return (size);
}

int		rewrite_ind(int input, int output)
{
	int ind;

	ind = 0;
	read(input, &ind, 2);
	ind = ((ind >> 8) & 0xff) | ((ind << 8) & 0xff00);
	if (ind > 32767)
		ind = -1 * (65535 - ind + 1);
	ft_writenbr(output, ind);
	return (2);
}

int		rewrite_reg(int input, int output)
{
	int reg;

	reg = 0;
	read(input, &reg, 1);
	if (reg > REG_NUMBER || reg == 0)
		ft_error("Bad register number", 0);
	write(output, "r", 1);
	ft_writenbr(output, reg);
	return (1);
}
