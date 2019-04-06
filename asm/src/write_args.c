/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:36:23 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/27 15:44:42 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_label(t_label *label, char **file)
{
	char	*tmp;
	char	*ptr;
	char	c[2];

	tmp = ft_strdup("");
	c[1] = '\0';
	while (ft_strchr(LABEL_CHARS, **file))
	{
		ptr = tmp;
		c[0] = **file;
		tmp = ft_strjoin(tmp, c);
		free(ptr);
		(*file)++;
	}
	while (label)
	{
		if (ft_strequ(label->name, tmp))
		{
			free(tmp);
			return (label->pos - g_size);
		}
		label = label->next;
	}
	ft_error("Unknown label.", 0);
	return (0);
}

int		write_dir(int fd, t_label *l, char **file, int ty)
{
	int tmp;
	int size;

	if (**file != DIRECT_CHAR)
		return (0);
	size = (ty == 1 || ty == 2 || ty == 13 || ty == 6 || ty == 7 ||
		ty == 8) ? 4 : 2;
	if (++(*file) && **file == LABEL_CHAR)
	{
		(*file)++;
		tmp = count_label(l, file);
	}
	else
		tmp = ft_atoi(*file);
	magic_write(fd, &tmp, size);
	g_current_pos += size;
	while (**file && **file != ',' && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return (1);
	(*file)++;
	while (**file && (**file == ' ' || **file == '\t'))
		(*file)++;
	return (1);
}

int		write_ind(int fd, t_label *l, char **file)
{
	int t;

	if (**file == LABEL_CHAR)
	{
		(*file)++;
		t = count_label(l, file);
	}
	else
		t = ft_atoi(*file);
	g_current_pos += 2;
	magic_write(fd, &t, 2);
	while (**file && **file != ',' && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return (1);
	(*file)++;
	while (**file && (**file == ' ' || **file == '\t'))
		(*file)++;
	return (1);
}

int		write_reg(int fd, char **file)
{
	int k;

	k = 0;
	if (**file != 'r')
		return (0);
	(*file)++;
	k = ft_atoi(*file);
	write(fd, &k, 1);
	g_current_pos++;
	while (**file && **file != ',' && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return (1);
	if (**file == ',')
		(*file)++;
	while (**file && (**file == ' ' || **file == '\t'))
		(*file)++;
	return (1);
}
