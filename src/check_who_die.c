/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_who_die.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:54:33 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 12:16:51 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	next_op(t_cursor *cursor)
{
	cursor->pos = find_adress(cursor->pos + cursor->step);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

int		is_die(t_cor *cor, t_cursor *cursor)
{
	return (cor->cycles_to_die <= 0
			|| cor->cycles - cursor->last_live >= cor->cycles_to_die);
}

void	check_cursors(t_cor *cor, t_cursor *prev)
{
	t_cursor *tmp;
	t_cursor *new;

	tmp = cor->cursor;
	while (tmp)
	{
		if (is_die(cor, tmp))
		{
			if (cor->visual)
				sound_die();
			new = tmp->next;
			free(tmp);
			if (prev)
				prev->next = new;
			else
				cor->cursor = new;
			tmp = new;
			cor->cursors--;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

void	check_who_die(t_cor *cor)
{
	int i;

	i = -1;
	cor->check_in++;
	check_cursors(cor, NULL);
	if (cor->check_in == MAX_CHECKS || cor->live_in >= NBR_LIVE)
	{
		cor->cycles_to_die -= CYCLE_DELTA;
		if (cor->log == 2)
			ft_printf("Cycle to die is now %i\n", cor->cycles_to_die);
		cor->check_in = 0;
	}
	while (++i < cor->count_heroes)
	{
		cor->heroes[i].last_live = cor->heroes[i].live;
		cor->heroes[i].live = 0;
	}
	cor->live_in = 0;
	cor->cycles_after_check = 0;
}
