/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:33:35 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/06 14:48:06 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <locale.h>
#include <signal.h>

void		update(WINDOW *win)
{
	refresh();
	wrefresh(win);
}

void		print_border(int y)
{
	wattron(g_win_status_bar, COLOR_PAIR(15));
	mvwprintw(g_win_status_bar, y, 1,
			"___________________________________________________________");
	mvwprintw(g_win_status_bar, ++y, 1,
			"___________________________________________________________");
	wattroff(g_win_status_bar, COLOR_PAIR(15));
}

static void	set_colors(void)
{
	start_color();
	assume_default_colors(255, 0);
	init_pair(15, 128, 0);
	init_pair(17, 255, 0);
	init_pair(16, 60, 0);
	init_pair(1, 34, 0);
	init_pair(2, 39, 0);
	init_pair(3, 226, 0);
	init_pair(4, 160, 0);
	init_pair(5, 255, 60);
	init_pair(6, 255, 34);
	init_pair(7, 255, 39);
	init_pair(8, 255, 226);
	init_pair(9, 255, 160);
}

void		init_win(t_cor *cor)
{
	system("echo \'\e[8;67;258t\'");
	g_music_set = ft_strdup("./music.sh 1 &");
	system(g_music_set);
	setlocale(LC_ALL, "");
	initscr();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	set_colors();
	g_win_arena = newwin(66, 195, 0, 0);
	g_win_status_bar = newwin(66, 61, 0, 195);
	g_delay = 1000;
	g_speed = 1;
	wattron(g_win_status_bar, A_BOLD | COLOR_PAIR(15));
	wattron(g_win_arena, (A_BOLD | COLOR_PAIR(15)));
	box(g_win_arena, 0, 0);
	box(g_win_status_bar, 0, 0);
	wattroff(g_win_arena, COLOR_PAIR(15));
	wattroff(g_win_status_bar, COLOR_PAIR(15));
	init_status_bar(cor);
	noecho();
	signal(SIGINT, dinit_win);
}
