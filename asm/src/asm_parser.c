/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:50:41 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/27 15:55:35 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_label(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] && ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == LABEL_CHAR && i > 0)
		return (1);
	else if (line[i] && line[i] != ' ' && line[i] != '\t' &&
		line[i] != COMMENT_CHAR &&
		line[i] != ALTERNATIVE_COMMENT && line[i] != '\n'
		&& line[i] != ',')
	{
		if (line[i + 1] == ' ' || line[i + 1] == '\n' || line[i + 1] == '\0')
			ft_error("Wrong format label_char.", g_line);
		else
			ft_error("Wrong format label_chars.", g_line);
	}
	return (0);
}

char		*add_line(int i, char *line, char *file)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != COMMENT_CHAR &&
		line[i] != ALTERNATIVE_COMMENT && check_line(&line[i]))
		file = join(file, (char *)&line[i]);
	return (file);
}

void		add_label(t_label **res, char *line, int i)
{
	t_label	*new;
	int		j;
	char	*ptr;
	char	*tmp;
	char	b[2];

	j = i;
	b[1] = '\0';
	tmp = ft_strdup("");
	if (!(new = malloc(sizeof(t_label))))
		ft_error("Error. Can't allocate memory", 0);
	while (line[j] && line[j] != LABEL_CHAR)
	{
		b[0] = line[j];
		ptr = tmp;
		tmp = ft_strjoin(tmp, b);
		free(ptr);
		j++;
	}
	new->name = tmp;
	new->pos = g_size;
	new->next = *res;
	*res = new;
}

t_label		*asm_parse_file(char **file, t_asm *s)
{
	char	*line;
	int		i;
	t_label	*res;

	res = NULL;
	while (get_next_line(s->fd, &line) > 0)
	{
		i = 0;
		g_line++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != COMMENT_CHAR && line[i] !=
			ALTERNATIVE_COMMENT && check_label(line) > 0)
		{
			add_label(&res, line, i);
			while (line[i] != LABEL_CHAR)
				i++;
			i++;
		}
		*file = add_line(i, line, *file);
		free(line);
	}
	return (res);
}

char		*start_parsing(t_asm *s, t_label **labels)
{
	char *file;

	file = NULL;
	make_header(s);
	*labels = asm_parse_file(&file, s);
	if ((s->new_fd = open(s->filename, O_CREAT | O_RDWR, 0644)) < 0)
		return (NULL);
	if (!file)
		ft_error("No player's executable code.", 0);
	return (file);
}
