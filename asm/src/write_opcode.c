/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_opcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:45:09 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/27 15:45:16 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_opcode(char *file, int check, int i)
{
	if (file[i] == 'r' && check == 0)
		return (0x40);
	else	if (file[i] == 'r' && check == 1)
		return (0x10);
	else	if (file[i] == 'r' && check == 2)
		return (0x4);
	else	if (file[i] == '%' && check == 0)
		return (0x80);
	else	if (file[i] == '%' && check == 1)
		return (0x20);
	else	if (file[i] == '%' && check == 2)
		return (0x8);
	else	if (check == 0)
		return (0xc0);
	else	if (check == 1)
		return (0x30);
	else
		return (0xc);
}

void	write_opcode(int args, char *file, int fd)
{
	int opcode;
	int check;
	int i;

	opcode = 0;
	check = 0;
	i = 0;
	while (check < args)
	{
		opcode = (opcode | get_opcode(file, check, i));
		if (check < args - 1)
		{
			while (file[i] != ',')
				i++;
			i++;
			while (file[i] == ' ' || file[i] == '\t')
				i++;
		}
		check++;
	}
	write(fd, &opcode, 1);
}

void	write_arg_code(int type, char *file, int fd)
{
	if (type == 4 || type == 5)
		write(fd, "T", 1);
	else	if (type == 16)
		write(fd, "@", 1);
	else
	{
		if (type == 2 || type == 13 || type == 3)
			write_opcode(2, file, fd);
		else
			write_opcode(3, file, fd);
	}
	(g_current_pos)++;
}
