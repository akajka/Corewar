/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:08:21 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/28 18:07:30 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name(t_asm *s, char *name)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = ft_strrchr(name, '.');
	if (!str || !ft_strequ(str, ".cor"))
		ft_error("The file isn't .cor extantion", 0);
	while (name[i])
	{
		if (ft_strequ(&name[i], ".cor"))
			break ;
		i++;
	}
	s->filename = ft_strnew(i + 4);
	s->filename = ft_strncpy(s->filename, name, i);
	s->filename = ft_strcat(s->filename, ".s");
}

int		handle_head(int input, int output, t_asm *s)
{
	unsigned int	magic;
	int				size;

	read(input, &magic, 4);
	if (magic != 0xf383ea00)
		ft_error("Wrong format of magic header", 0);
	write(output, ".name \"", 7);
	read(input, s->name, PROG_NAME_LENGTH);
	write(output, s->name, ft_strlen(s->name));
	write(output, "\"\n", 2);
	read(input, &magic, 4);
	read(input, &size, 4);
	read(input, s->comment, COMMENT_LENGTH);
	write(output, ".comment \"", 10);
	write(output, s->comment, ft_strlen(s->comment));
	write(output, "\"\n\n", 3);
	read(input, &magic, 4);
	return (((size >> 24) & 0xff) | ((size & 0xff0000) >> 8) |
		((size & 0xff00) << 8) | ((size << 24) & 0xff000000));
}

int		write_command(int type, int args, int output, int input)
{
	int res;

	res = 0;
	res += write_arg1(args, type, input, output);
	if ((args & 0x30) != 0)
	{
		write(output, ", ", 2);
		res += write_arg2(args, type, input, output);
	}
	if ((args & 0xc) != 0)
	{
		write(output, ", ", 2);
		res += write_arg3(args, type, input, output);
	}
	return (res);
}

void	dis_asm_exec(int size, int input, int output)
{
	int t;
	int type;
	int args;

	t = 0;
	while (t < size)
	{
		args = 0;
		read(input, &type, 1);
		t++;
		write(output, g_etable[type - 1], ft_strlen(g_etable[type - 1]));
		write(output, " ", 1);
		if (type != 1 && type != 9 &&
			type != 12 && type != 15)
		{
			read(input, &args, 1);
			t++;
		}
		t += write_command(type, args, output, input);
		write(output, "\n", 1);
	}
}

void	start_disasm(t_asm *s, char *name)
{
	int size;

	check_name(s, name);
	if ((s->fd = open(name, O_RDONLY)) < 0 || read(s->fd, 0, 0) == -1)
		ft_error("Can't open or read the file!", 0);
	if ((s->new_fd = open(s->filename, O_CREAT | O_RDWR, 0644)) < 0)
		ft_error("Something went wrong.", 0);
	size = handle_head(s->fd, s->new_fd, s);
	dis_asm_exec(size, s->fd, s->new_fd);
	ft_printf("Writing output program to %s\n", s->filename);
	close(s->new_fd);
	close(s->fd);
}
