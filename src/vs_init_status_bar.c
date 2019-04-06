/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init_status_bar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:50 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 19:04:47 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_players_info(t_cor *cor)
{
	int		y;
	int		len;
	int		i;

	y = 17;
	i = -1;
	while (++i < cor->count_heroes && (y += 2))
	{
		mvwprintw(g_win_status_bar, ++y, 5, "PLAYER NUMBER %d", i + 1);
		mvwprintw(g_win_status_bar, ++y, 7, "name:");
		wattron(g_win_status_bar, COLOR_PAIR(i + 1));
		len = ft_strlen(cor->heroes[i].name);
		if (len > 30)
		{
			mvwprintw(g_win_status_bar, y, 14, "%.*s", len / 2,
					cor->heroes[i].name, &cor->heroes[i].name[len / 2]);
			mvwprintw(g_win_status_bar, ++y, 8, &cor->heroes[i].name[len / 2]);
		}
		else
			mvwprintw(g_win_status_bar, y, 14, "%s", cor->heroes[i].name);
		wattroff(g_win_status_bar, COLOR_PAIR(i + 1));
		mvwprintw(g_win_status_bar, ++y, 7, "last live:");
		mvwprintw(g_win_status_bar, ++y, 7, "lives in current period:");
	}
}

void		print_header(void)
{
	mvwprintw(g_win_status_bar, 1, 1, "%S",
			L" ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗ ");
	mvwprintw(g_win_status_bar, 2, 1, "%S",
			L"██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗");
	mvwprintw(g_win_status_bar, 3, 1, "%S",
			L"██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝");
	mvwprintw(g_win_status_bar, 4, 1, "%S",
			L"██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗");
	mvwprintw(g_win_status_bar, 5, 1, "%S",
			L"╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║");
	mvwprintw(g_win_status_bar, 6, 1, "%S",
			L" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝");
	print_border(7);
}

void		init_status_bar(t_cor *cor)
{
	print_header();
	mvwprintw(g_win_status_bar, 11, 5, "CYCLE :");
	mvwprintw(g_win_status_bar, 12, 5, "CYCLE BEFORE CHECK :");
	mvwprintw(g_win_status_bar, 13, 5, "CYCLE TO DIE :");
	mvwprintw(g_win_status_bar, 14, 5, "CYCLE DELTA :");
	mvwprintw(g_win_status_bar, 15, 5, "PROCESSES :");
	print_border(16);
	print_players_info(cor);
	print_border(48);
	print_control_key();
	update(g_win_status_bar);
}
