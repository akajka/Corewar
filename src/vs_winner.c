/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:49:34 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/06 14:18:10 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			winner_ban(void)
{
	int			y;
	int			x;

	y = getmaxy(stdscr) / 2 - 6;
	x = getmaxx(stdscr) / 2 - 25;
	wattron(stdscr, COLOR_PAIR(17));
	mvwprintw(stdscr, y++, x, "%S",
			L"██╗    ██╗██╗███╗   ██╗███╗   ██╗███████╗██████╗ ");
	mvwprintw(stdscr, y++, x, "%S",
			L"██║    ██║██║████╗  ██║████╗  ██║██╔════╝██╔══██╗");
	mvwprintw(stdscr, y++, x, "%S",
			L"██║ █╗ ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝");
	mvwprintw(stdscr, y++, x, "%S",
			L"██║███╗██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗");
	mvwprintw(stdscr, y++, x, "%S",
			L"╚███╔███╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║");
	mvwprintw(stdscr, y++, x, "%S",
			L" ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝");
	wattroff(stdscr, COLOR_PAIR(17));
}

void			get_color(int id)
{
	static char	*color[4] = {"\033[32m",
		"\033[34m",
		"\033[33m",
		"\033[31m"};

	printf("%s", color[id]);
}

void			winner(t_hero winner)
{
	int			y;
	int			x;
	int			col;
	int			len;

	update(stdscr);
	y = getmaxy(stdscr) * 3;
	x = getmaxx(stdscr) * 3;
	get_color(winner.id);
	len = ft_strlen(winner.name);
	while (y--)
	{
		col = x / 2;
		while (col--)
			printf("%c ", ft_toupper(winner.name[col % len]));
	}
	winner_ban();
	while (getch() != KEY_ESC)
		;
	dinit_win();
}
