/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:13:05 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/20 17:13:27 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_separator(char **line)
{
	while (**line == '\t' || **line == ' ')
		(*line)++;
	if (**line != SEPARATOR_CHAR)
		ft_error("No SEPARATOR_CHAR.", g_line);
	(*line)++;
	while (**line == '\t' || **line == ' ')
		(*line)++;
	return (1);
}

int		dir(char **line, int type, int t)
{
	if (**line == DIRECT_CHAR)
	{
		if (t == 1 || t == 2 || t == 6 || t == 7 ||
		t == 8 || t == 13)
			g_size += 4;
		else
			g_size += 2;
		(*line)++;
		if (**line != LABEL_CHAR && (**line < '0' || **line > '9')
			&& **line != '+' && **line != '-')
			ft_error("Bad T_DIR argument format.", g_line);
		if (**line && (**line == LABEL_CHAR || **line == '+' || **line == '-'))
			(*line)++;
		while (**line && ft_strchr(LABEL_CHARS, **line))
			(*line)++;
		if (type == 1)
			return (check_separator(line));
		return (1);
	}
	return (0);
}

int		reg(char **line, int type)
{
	int reg;

	reg = 0;
	if (**line == 'r')
	{
		g_size++;
		(*line)++;
		reg = ft_atoi(*line);
		if (reg > 16 || reg <= 0)
			ft_error("Wrong register number.", g_line);
		while (**line >= '0' && **line <= '9')
			(*line)++;
		if (type == 1)
			return (check_separator(line));
		return (1);
	}
	return (0);
}

int		ind(char **li, int type)
{
	if (**li == LABEL_CHAR || **li == '+' ||
		**li == '-' || (**li >= '0' && **li <= '9'))
	{
		if (**li == LABEL_CHAR)
		{
			(*li)++;
			while (**li && ft_strchr(LABEL_CHARS, **li))
				(*li)++;
		}
		else if (**li == '+' || **li == '-' || (**li >= '0' && **li <= '9'))
		{
			if (**li == '+' || **li == '-')
				(*li)++;
			while (**li && ft_isdigit(**li))
				(*li)++;
		}
		if (**li != ' ' && **li != '\t' && **li != SEPARATOR_CHAR
			&& **li != '\0' && **li != '\n')
			ft_error("Bad T_IND argument format.", g_line);
		g_size += 2;
		if (type == 1)
			return (check_separator(li));
		return (1);
	}
	return (0);
}
