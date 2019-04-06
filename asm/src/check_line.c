/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:06:57 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/20 17:09:26 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int		check_type(char *line, int *type)
{
	int i;
	int tmp;

	i = 0;
	tmp = -1;
	while (g_etable[i])
	{
		if (ft_strncmp(line, g_etable[i], ft_strlen(g_etable[i])) == 0)
		{
			if (tmp == -1)
				tmp = i;
			else	if (ft_strlen(g_etable[i]) > ft_strlen(g_etable[tmp]))
				tmp = i;
		}
		i++;
	}
	if (tmp < 0)
	{
		*type = 0;
		return (0);
	}
	*type = tmp + 1;
	return (ft_strlen(g_etable[tmp]));
}

int		check(char **line, int type)
{
	if ((reg(line, 1) || dir(line, 1, type) || ind(line, 1)) &&
		(reg(line, 1) || dir(line, 1, type) || ind(line, 1)) &&
	reg(line, 0))
		return (1);
	return (0);
}

int		check2(char **line, int type)
{
	if ((reg(line, 1) || dir(line, 1, type) || ind(line, 1)) &&
		(reg(line, 1) || dir(line, 1, type)) && reg(line, 0))
		return (1);
	return (0);
}

int		check_args(char **line, int typ)
{
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
	if ((typ == 1 || typ == 9 || typ == 12 || typ == 15))
		return (dir(line, 0, typ));
	else	if ((typ == 2 || typ == 13) && (dir(line, 1, typ) || ind(line, 1))
		&& reg(line, 0))
		return (1);
	else	if (typ == 3 && reg(line, 1) && (reg(line, 0) || ind(line, 0)))
		return (1);
	else	if ((typ == 4 || typ == 5) && reg(line, 1) &&
	reg(line, 1) && reg(line, 0))
		return (1);
	else	if ((typ == 6 || typ == 7 || typ == 8))
		return (check(line, typ));
	else	if (typ == 10 || typ == 14)
		return (check2(line, typ));
	else	if (typ == 11 && reg(line, 1) &&
		(reg(line, 1) || dir(line, 1, typ) || ind(line, 1)) &&
		(reg(line, 0) || dir(line, 0, typ)))
		return (1);
	else	if (typ == 16)
		return (reg(line, 0));
	else
		return (0);
}

int		check_line(char *line)
{
	int type;
	int size;

	if ((size = check_type(line, &type)) == 0 || type == 0)
		ft_error("Wrong instruction.", g_line);
	g_size++;
	if (type != 1 && type != 9 && type != 12 && type != 15)
		g_size++;
	line = line + size;
	if (check_args(&line, type) == 0)
		ft_error("Wrong argument format.", g_line);
	while (*line && *line != COMMENT_CHAR && *line != ';')
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			ft_error("Syntax error.", g_line);
		line++;
	}
	return (1);
}
