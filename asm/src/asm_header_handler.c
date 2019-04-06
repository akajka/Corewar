/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:09:12 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/20 17:19:48 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	magic_write(int dst, int *buf, size_t len)
{
	int n;

	if (len == 4)
		n = ((*buf >> 24) & 0xff) | ((*buf & 0xff0000) >> 8) |
		((*buf & 0xff00) << 8) | ((*buf << 24) & 0xff000000);
	else	if (len == 2)
		n = ((*buf >> 8) & 0xff) | ((*buf << 8) & 0xff00);
	else
		n = *buf;
	write(dst, &n, len);
}

int		get_the_beginning(char *str, int a)
{
	int i;

	i = a;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] != '"')
	{
		if (a == 5)
			ft_error("Bad player's name format", g_line);
		else
			ft_error("Bad player's comment format", g_line);
	}
	i++;
	return (i);
}

void	get_name_com(t_asm *s, char *str, char *name_flag, char *com_flag)
{
	int i;

	i = 0;
	if (*name_flag == 0 && ft_strncmp(str, NAME_CMD_STRING, 5) == 0)
	{
		i = get_the_beginning(str, 5);
		make_name(str + i, s);
		*name_flag = 1;
	}
	else	if (*com_flag == 0 && ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0)
	{
		i = get_the_beginning(str, 8);
		make_comment(str + i, s);
		*com_flag = 1;
	}
	else
		ft_error("Impossible to find name or comment.", 0);
}

void	make_header(t_asm *s)
{
	int		i;
	char	*line;
	char	name_flag;
	char	com_flag;

	i = 0;
	line = NULL;
	name_flag = 0;
	com_flag = 0;
	while (get_next_line(s->fd, &line) > 0)
	{
		g_line++;
		if (line[0] != COMMENT_CHAR && line[0] != ';' && line[0])
		{
			while ((line[i] == ' ' || line[i] == '\t') && line[i])
				i++;
			get_name_com(s, line + i, &name_flag, &com_flag);
		}
		free(line);
		line = NULL;
		if (name_flag == 1 && com_flag == 1)
			break ;
	}
}
