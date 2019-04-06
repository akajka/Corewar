/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:07:31 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 14:45:05 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_players(t_cor *cor)
{
	int id;

	id = -1;
	ft_printf("Introducing contestants...\n");
	while (++id < cor->count_heroes)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				id + 1, cor->heroes[id].size, cor->heroes[id].name,
				cor->heroes[id].comment);
	}
}

void	print_last_alive(t_cor *cor)
{
	ft_printf("Player %d \"%s\" won!\n", cor->last_alive + 1,
			cor->heroes[cor->last_alive].name);
	if (cor->visual)
		winner(cor->heroes[cor->last_alive]);
}

void	print_help(void)
{
	int			i;
	const char	*help[8] = {"Usage: ./corewar [-d N | -v | -l N | ",
		"[-a ] | -n N ] <champ.cor> <...>\n\n",
		"\t-a        : Prints output from \"aff\" (Default is to hide it)\n",
		"\t-d N      : Dumps memory after N cycles then exits\n",
		"\t-v        : Ncurses output mode\n",
		"\t-l N      : Verbosity levels\n",
		"\t\t\t- 1 : Show lives\n\t\t\t- 2 : Show cycles\n",
		"\t-n N      : Set player's id\n"};

	i = -1;
	while (++i < 8)
		ft_printf("%s", help[i]);
	exit(1);
}

void	print_live(t_cor *cor, int id)
{
	ft_printf("A process shows that player %i %s is alive\n",
			id + 1, cor->heroes[id].name);
}

void	print_arena(t_cor *cor)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < 32)
		{
			ft_printf("%.2x ", cor->stage[i + j]);
			j++;
		}
		ft_printf("\n");
		i += 32;
	}
}
