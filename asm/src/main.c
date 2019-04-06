/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:18:03 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/28 18:11:04 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(char *s, int i)
{
	if (i == 0)
		ft_printf("Error. %s\n", s);
	else
		ft_printf("Error. Line %d: %s\n", i, s);
	exit(1);
}

void	init(t_asm *s)
{
	ft_bzero(s->name, PROG_NAME_LENGTH + 1);
	ft_bzero(s->comment, COMMENT_LENGTH + 1);
	s->filename = NULL;
	s->magic = COREWAR_EXEC_MAGIC;
	s->fd = 0;
	s->new_fd = 0;
	g_size = 0;
	g_line = 0;
}

void	check_av(char **av, t_asm *s)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	str = ft_strrchr(av[1], '.');
	if (!str || !ft_strequ(str, ".s"))
		ft_error("The file isn't .s extantion!", 0);
	while (av[1][i])
	{
		if (av[1][i] == '.' && av[1][i + 1] == 's')
			break ;
		i++;
	}
	s->filename = ft_strnew(i + 4);
	s->filename = ft_strncpy(s->filename, av[1], i);
	s->filename = ft_strcat(s->filename, ".cor");
}

void	ft_usage(void)
{
	ft_printf("Usage: ./asm [-b] <file>\n");
	ft_printf("   -b <file.cor>  : Disassembler for .cor file.\n");
}

int		main(int ac, char **av)
{
	t_asm	s;
	char	*file;
	t_label	*labels;

	file = NULL;
	labels = NULL;
	if (ac == 2)
	{
		init(&s);
		check_av(av, &s);
		if ((s.fd = open(av[1], O_RDONLY)) < 0 || read(s.fd, 0, 0) == -1)
			ft_error("Can't read the source file!", 0);
		file = start_parsing(&s, &labels);
		close(s.fd);
		write_file(&s, file, labels);
		close(s.new_fd);
	}
	else	if (ac == 3 && ft_strequ(av[1], "-b"))
	{
		init(&s);
		start_disasm(&s, av[2]);
	}
	else
		ft_usage();
	return (0);
}
