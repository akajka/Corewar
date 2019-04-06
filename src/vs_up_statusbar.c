/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_up_statusbar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 07:20:43 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 18:57:13 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		update_bar(t_cor *cor)
{
	int		y;
	int		len;
	int		i;

	y = 17;
	i = -1;
	while (++i < cor->count_heroes && (y += 4))
	{
		wattron(g_win_status_bar, COLOR_PAIR(i + 1));
		len = ft_strlen(cor->heroes[i].name);
		if (len > 30)
			y++;
		mvwprintw(g_win_status_bar, ++y, 18, "%-10d", cor->heroes[i].last_live);
		mvwprintw(g_win_status_bar, ++y, 32, "%-10d", cor->heroes[i].live);
		wattroff(g_win_status_bar, COLOR_PAIR(i + 1));
	}
	mvwprintw(g_win_status_bar, 11, 13, "%-10d", cor->cycles);
	mvwprintw(g_win_status_bar, 12, 26, "%-10d", cor->cycles_to_die
			- cor->cycles_after_check);
	mvwprintw(g_win_status_bar, 13, 20, "%-10d", cor->cycles_to_die);
	mvwprintw(g_win_status_bar, 14, 19, "%-10d", CYCLE_DELTA);
	mvwprintw(g_win_status_bar, 15, 17, "%-10d", cor->live_in);
	update(g_win_status_bar);
}
