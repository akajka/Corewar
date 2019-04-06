/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:11:07 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 12:23:33 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_case(char *str)
{
	if (str)
	{
		ft_printf("usage corewar:\n\n\tprint symbols:\t\t-a\n\n");
		ft_printf("\tlog level:\n\t\t-l 1 \n\t\t-l 2\n\n");
		ft_printf("\tprint memory\n\t\t-d N\n\t\t--dump N\n\n");
		ft_printf("\tvisual:\n\t\t-v\n\n");
		ft_printf("\tset number of player:\n\t\t-n N\n\n");
	}
	exit(1);
}

int		main(int argc, char **argv)
{
	t_cor cor;

	ft_bzero(&cor, sizeof(t_cor));
	cor.dump_cycle = -2;
	cor.cycles_to_die = CYCLE_TO_DIE;
	read_flags(&cor, argc, argv);
	validate_heroes(&cor);
	init_game(&cor);
	print_players(&cor);
	if (cor.visual == 1)
		init_win(&cor);
	full_game(&cor);
	print_last_alive(&cor);
}
