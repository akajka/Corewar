/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_control_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:43:44 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 19:07:07 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cursor_plus(t_cor *cor)
{
	t_cursor	*cur;

	cur = cor->cursor;
	while (cur)
	{
		if (cor->field[cur->pos % MEM_SIZE] < 5)
			cor->field[cur->pos % MEM_SIZE] += 5;
		cur = cur->next;
	}
}

void			cursor_noun(t_cor *cor)
{
	t_cursor	*cur;

	cur = cor->cursor;
	while (cur)
	{
		if (cor->field[cur->pos % MEM_SIZE] > 4)
			cor->field[cur->pos % MEM_SIZE] -= 5;
		cur = cur->next;
	}
}

void			update_arena(t_cor *cor)
{
	int x;
	int y;
	int i;

	i = -1;
	x = 2;
	y = 0;
	cursor_plus(cor);
	while (++i < MEM_SIZE)
	{
		wattron(g_win_arena, COLOR_PAIR(16));
		if (i % 64 == 0 && ++y)
			x = 2;
		if (cor->field[i])
			wattron(g_win_arena, COLOR_PAIR(cor->field[i]));
		mvwprintw(g_win_arena, y, x, "%02x", cor->stage[i]);
		x += 3;
	}
	cursor_noun(cor);
	update(g_win_arena);
	key_control();
	usleep(g_delay);
}
