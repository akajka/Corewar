/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:21:42 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 19:00:01 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			print_control_key(void)
{
	mvwprintw(g_win_status_bar, 52, 20, "OPTIONS");
	mvwprintw(g_win_status_bar, 54, 5, "[SPACE] == pause/resume");
	mvwprintw(g_win_status_bar, 55, 5, "[↑] == speed++++");
	mvwprintw(g_win_status_bar, 56, 5, "[↓] == speed----");
	mvwprintw(g_win_status_bar, 57, 5, "[ESC] == exit");
}

static void		pause_mode(void)
{
	int			ch;

	mvwprintw(g_win_status_bar, 64, 45, "             ");
	mvwprintw(g_win_status_bar, 64, 52, "PAUSE");
	system("killall sh music.sh afplay");
	update(g_win_status_bar);
	while ((ch = getch()) != KEY_SPACE)
		if (ch == KEY_ESC)
			dinit_win();
	mvwprintw(g_win_status_bar, 64, 52, "     ");
	update(g_win_status_bar);
	system(g_music_set);
}

static void		speed_up(void)
{
	char		tmp[30];
	char		sp[10];

	ft_strclr(sp);
	mvwprintw(g_win_status_bar, 64, 45, "             ");
	if (g_speed < 1.6)
	{
		ft_strdel(&g_music_set);
		g_delay /= 5;
		g_speed += 0.2;
		ft_strcpy(tmp, "./music.sh ");
		ftoa(g_speed, sp, 1);
		mvwprintw(g_win_status_bar, 64, 45, "Speed ↑ = %s", sp);
		ft_strcat(tmp, sp);
		ft_strcat(tmp, " &");
		g_music_set = ft_strdup(tmp);
		system("killall sh music.sh afplay");
		system(g_music_set);
	}
	else
		mvwprintw(g_win_status_bar, 64, 45, "Its max speed");
	update(g_win_status_bar);
}

static void		slow_down(void)
{
	char		tmp[30];
	char		sp[10];

	ft_strclr(sp);
	mvwprintw(g_win_status_bar, 64, 45, "             ");
	if (g_speed > 0.6)
	{
		ft_strdel(&g_music_set);
		g_delay *= 5;
		g_speed -= 0.2;
		ft_strcpy(tmp, "./music.sh ");
		ftoa(g_speed, sp, 1);
		mvwprintw(g_win_status_bar, 64, 45, "Speed ↓ = %s", sp);
		ft_strcat(tmp, sp);
		ft_strcat(tmp, " &");
		g_music_set = ft_strdup(tmp);
		system("killall sh music.sh afplay");
		system(g_music_set);
	}
	else
		mvwprintw(g_win_status_bar, 64, 45, "Its min speed");
	update(g_win_status_bar);
}

void			key_control(void)
{
	int			ch;

	ch = getch();
	if (ch)
	{
		if (ch == KEY_ESC)
			dinit_win();
		else if (ch == KEY_SPACE)
			pause_mode();
		else if (ch == KEY_UP)
			speed_up();
		else if (ch == KEY_DOWN)
			slow_down();
	}
}
