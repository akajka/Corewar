/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:21:17 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/20 18:12:44 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_head(t_asm *s)
{
	int i;

	i = 0;
	magic_write(s->new_fd, &s->magic, 4);
	while (i < PROG_NAME_LENGTH)
		write(s->new_fd, &s->name[i++], 1);
	write(s->new_fd, "\0\0\0\0", 4);
	magic_write(s->new_fd, &g_size, 4);
	i = 0;
	while (i < COMMENT_LENGTH)
		write(s->new_fd, &s->comment[i++], 1);
	write(s->new_fd, "\0\0\0\0", 4);
	g_size = 0;
	g_line = 0;
}

int		write_exec_code(char **f, int t, t_label *l, int fd)
{
	if (t == 1 || t == 9 || t == 12 || t == 15)
		return (write_dir(fd, l, f, t));
	if ((t == 2 || t == 13) && (write_dir(fd, l, f, t) ||
		write_ind(fd, l, f)))
		return (write_reg(fd, f));
	if (t == 3 && write_reg(fd, f) && (write_reg(fd, f) || write_ind(fd, l, f)))
		return (1);
	if ((t == 4 || t == 5) && write_reg(fd, f) && write_reg(fd, f))
		return (write_reg(fd, f));
	if ((t == 6 || t == 7 || t == 8) &&
		(write_dir(fd, l, f, t) || write_reg(fd, f) || write_ind(fd, l, f))
		&& (write_dir(fd, l, f, t) || write_reg(fd, f) || write_ind(fd, l, f)))
		return (write_reg(fd, f));
	if ((t == 10 || t == 14) && (write_dir(fd, l, f, t)
		|| write_reg(fd, f) || write_ind(fd, l, f)) &&
		(write_dir(fd, l, f, t) || write_reg(fd, f)))
		return (write_reg(fd, f));
	if (t == 11 && write_reg(fd, f) &&
		(write_dir(fd, l, f, t) || write_reg(fd, f) || write_ind(fd, l, f))
		&& (write_dir(fd, l, f, t) || write_reg(fd, f)))
		return (1);
	if (t == 16)
		return (write_reg(fd, f));
	return (0);
}

void	write_file(t_asm *s, char *file, t_label *labels)
{
	int		type;
	char	*tmp;

	tmp = file;
	write_head(s);
	while (*file)
	{
		g_line++;
		g_current_pos = 0;
		file += check_type(file, &type);
		if (type)
			g_current_pos++;
		while (*file == ' ' || *file == '\t')
			file++;
		write(s->new_fd, &type, 1);
		if (type != 1 && type != 9 && type != 15 && type != 12)
			write_arg_code(type, file, s->new_fd);
		write_exec_code(&file, type, labels, s->new_fd);
		while (*file && *file != '\n')
			file++;
		file++;
		g_size += g_current_pos;
	}
	free(tmp);
	ft_printf("Writing output program to %s\n", s->filename);
}
