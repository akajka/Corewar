/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_name_com.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:51:05 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/28 18:09:04 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	make_name2(t_asm *s, int i)
{
	int		t;
	char	*line;

	while (get_next_line(s->fd, &line) > 0)
	{
		g_line++;
		t = 0;
		ft_strcat(s->name, "\n");
		while (line[t] && line[t] != '"')
			t++;
		i += t + 1;
		if (i > PROG_NAME_LENGTH)
			ft_error("Name is to big.", 0);
		ft_strncat(s->name, line, t);
		if (line[t] == '"')
			break ;
		free(line);
	}
	t++;
	while (line[t] && line[t] != COMMENT_CHAR && line[t] != ';')
	{
		if (line[t] != ' ' && line[t] != '\t' && line[t] != '\n')
			ft_error("Syntax error", g_line);
		t++;
	}
}

void	make_name(char *str, t_asm *s)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '"')
		i++;
	if (i > PROG_NAME_LENGTH)
		ft_error("Name is too big.", 0);
	ft_strncpy(s->name, str, i);
	if (!str[i])
		make_name2(s, i);
}

void	make_comment2(t_asm *s, int i)
{
	int		t;
	char	*line;

	while (get_next_line(s->fd, &line) > 0)
	{
		g_line++;
		t = 0;
		ft_strcat(s->comment, "\n");
		while (line[t] && line[t] != '"')
			t++;
		i += t + 1;
		if (i > COMMENT_LENGTH)
			ft_error("Comment is to big.", 0);
		ft_strncat(s->comment, line, t);
		if (line[t] == '"')
			break ;
		free(line);
	}
	t++;
	while (line[t] && line[t] != COMMENT_CHAR && line[t] != ';')
	{
		if (line[t] != ' ' && line[t] != '\t' && line[t] != '\n')
			ft_error("Syntax error", g_line);
		t++;
	}
}

void	make_comment(char *str, t_asm *s)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '"')
		i++;
	if (i > COMMENT_LENGTH)
		ft_error("Comment is too big.", 0);
	ft_strncpy(s->comment, str, i);
	if (!str[i])
		make_comment2(s, i);
}
