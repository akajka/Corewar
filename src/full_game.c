/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:38:17 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 10:24:25 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		make_step(t_cursor *cursor, t_operation *operation)
{
	int		i;
	int		step;

	i = -1;
	step = 0;
	step += 1 + (operation->args_types_code ? 1 : 0);
	while (++i < g_op[cursor->operation - 1].args_num)
		step += count_step(cursor->args_types[i], operation);
	return (step);
}

void	set_operation(t_cor *cor, t_cursor *cursor)
{
	cursor->operation = cor->stage[cursor->pos];
	if (cor->stage[cursor->pos] >= 0x01 && cor->stage[cursor->pos] <= 0x10)
		cursor->cycle_wait = g_op[cursor->operation - 1].cycles;
}

void	check_cursor(t_cursor *cursor, t_cor *cor)
{
	t_operation	*new;

	if (!cursor->cycle_wait)
		set_operation(cor, cursor);
	if (cursor->cycle_wait > 0)
		cursor->cycle_wait--;
	if (!cursor->cycle_wait)
	{
		new = NULL;
		if (cursor->operation >= 0x01 && cursor->operation <= 0x10)
			new = &g_op[cursor->operation - 1];
		if (new)
		{
			read_argtype(cor, cursor, new);
			if (validate_args(cursor, new) && check_args(cursor, cor, new))
				new->func(cor, cursor);
			else
				cursor->step += make_step(cursor, new);
		}
		else
			cursor->step = 1;
	}
	next_op(cursor);
}

void	run_cycle(t_cor *cor)
{
	t_cursor *tmp;

	cor->cycles++;
	cor->cycles_after_check++;
	if (cor->visual)
		update_bar(cor);
	tmp = cor->cursor;
	while (tmp)
	{
		check_cursor(tmp, cor);
		tmp = tmp->next;
	}
}

void	full_game(t_cor *cor)
{
	if (cor->visual)
		update_arena(cor);
	while (cor->cursors)
	{
		if (cor->log == 2)
			ft_printf("It is now cycle %llu, after check %i\n",
					cor->cycles + 1, cor->cycles_after_check + 1);
		if (cor->dump_cycle == cor->cycles)
		{
			print_arena(cor);
			exit(1);
		}
		run_cycle(cor);
		if (cor->cycles_to_die == cor->cycles_after_check ||
				cor->cycles_to_die <= 0)
			check_who_die(cor);
		update_arena(cor);
	}
}
