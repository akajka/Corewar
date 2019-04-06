/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:56:01 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/27 15:56:05 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*join_line(char *dst, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(line) + ft_strlen(dst) + 1);
	tmp = ft_strcpy(tmp, dst);
	tmp = ft_strcat(tmp, line);
	while (tmp[i])
		i++;
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	free(dst);
	dst = ft_strdup(tmp);
	free(tmp);
	return (dst);
}

char		*join(char *dst, char *line)
{
	int		i;

	i = 0;
	if (*line)
	{
		if (dst == NULL)
		{
			dst = ft_strnew(ft_strlen(line) + 1);
			dst = ft_strcpy(dst, line);
			while (dst[i])
				i++;
			dst[i] = '\n';
			dst[i + 1] = '\0';
		}
		else
			dst = join_line(dst, line);
	}
	return (dst);
}
