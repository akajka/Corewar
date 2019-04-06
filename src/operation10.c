/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:12:26 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 12:24:19 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_sti(t_cor *cor, t_cursor *cursor)
{
	int32_t	reg;
	int32_t	value;
	int32_t	arg2;
	int32_t	arg3;

	cursor->step += OP_LEN + ARG_LEN;
	reg = cor->stage[find_adress(cursor->pos + cursor->step)];
	value = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	arg2 = take_op(cor, cursor, 2, 1);
	arg3 = take_op(cor, cursor, 3, 1);
	int_to_byte(cor, cursor->pos + (arg2 + arg3) % IDX_MOD, value, DIR_SIZE);
	set_field(cor, cursor->pos + (arg2 + arg3) % IDX_MOD,
			cor->field[cursor->pos], DIR_SIZE);
}

void				op_fork(t_cor *cor, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_LEN;
	addr = take_op(cor, cursor, 1, 1);
	new = copy_cursor(cursor, addr % IDX_MOD);
	new->next = cor->cursor;
	cor->cursor = new;
	cor->cursors++;
}

void				op_lld(t_cor *cor, t_cursor *cursor)
{
	int32_t	v;
	int32_t	reg;

	cursor->step += (OP_LEN + ARG_LEN);
	v = take_op(cor, cursor, 1, 0);
	cursor->carry = !v;
	reg = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = v;
	cursor->step += REG_LEN;
}

void				op_lldi(t_cor *cor, t_cursor *cursor)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	a1 = take_op(cor, cursor, 1, 1);
	a2 = take_op(cor, cursor, 2, 1);
	reg = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = byte_to_int(cor, cursor->pos + a1 + a2, DIR_SIZE);
	cursor->step += REG_LEN;
}

void				op_lfork(t_cor *cor, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_LEN;
	addr = take_op(cor, cursor, 1, 1);
	new = copy_cursor(cursor, addr);
	new->next = cor->cursor;
	cor->cursor = new;
	cor->cursors++;
}
