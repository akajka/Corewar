/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:09:54 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 13:09:53 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_live(t_cor *cor, t_cursor *cursor)
{
	int		id;
	t_hero	*hero;

	cursor->step += OP_LEN;
	id = take_op(cor, cursor, 1, 0);
	cor->live_in++;
	cursor->last_live = cor->cycles;
	hero = NULL;
	if (id <= -1 && id >= -cor->count_heroes)
	{
		if (id < 0)
			id *= -1;
		hero = &cor->heroes[id - 1];
		hero->last_live = cor->cycles;
		hero->live++;
		cor->last_alive = id - 1;
		if (cor->log == 1)
			ft_printf("Player %i (%s) is said to be alive\n", id, hero->name);
	}
}

void				op_ld(t_cor *cor, t_cursor *cursor)
{
	int32_t	value;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	value = take_op(cor, cursor, 1, 1);
	cursor->carry = !value;
	reg = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = value;
	cursor->step += REG_LEN;
}

void				op_st(t_cor *cor, t_cursor *cursor)
{
	int32_t	reg;
	int32_t	i;
	int32_t	addr;

	cursor->step += OP_LEN + ARG_LEN;
	reg = cor->stage[find_adress(cursor->pos + cursor->step)];
	i = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	if (cursor->args_types[1] == T_REG)
	{
		addr = cor->stage[find_adress(cursor->pos + cursor->step)];
		cursor->reg[addr - 1] = i;
		cursor->step += REG_LEN;
	}
	else
	{
		addr = byte_to_int(cor, cursor->pos + cursor->step, IND_SIZE);
		int_to_byte(cor, cursor->pos + (addr % IDX_MOD), i, DIR_SIZE);
		cursor->step += IND_SIZE;
		set_field(cor, cursor->pos + addr % IDX_MOD,
				cor->field[cursor->pos], DIR_SIZE);
	}
}

void				op_add(t_cor *cor, t_cursor *cursor)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	cursor->step += OP_LEN + ARG_LEN;
	reg1 = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->step += REG_LEN;
	reg2 = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->step += REG_LEN;
	i = cursor->reg[reg1 - 1] + cursor->reg[reg2 - 1];
	cursor->carry = !i;
	reg3 = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg3 - 1] = i;
	cursor->step += REG_LEN;
}

void				op_sub(t_cor *cor, t_cursor *cursor)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	cursor->step += (OP_LEN + ARG_LEN);
	reg1 = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->step += REG_LEN;
	reg2 = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->step += REG_LEN;
	i = cursor->reg[reg1 - 1] - cursor->reg[reg2 - 1];
	cursor->carry = !i;
	reg3 = cor->stage[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg3 - 1] = i;
	cursor->step += REG_LEN;
}
