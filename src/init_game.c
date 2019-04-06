/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:28:58 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/05 14:04:13 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*create_cursor(int id, int pos)
{
	t_cursor		*cursor;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		error_case("Memory error");
	cursor->id = id;
	cursor->carry = 0;
	cursor->last_live = 0;
	cursor->pos = pos;
	cursor->operation = 0;
	cursor->cycle_wait = 0;
	cursor->next = NULL;
	cursor->step = 0;
	ft_memset(&(cursor->reg), 0, 16);
	cursor->reg[0] = -(id + 1);
	return (cursor);
}

t_cursor	*copy_cursor(t_cursor *cursor, int32_t addr)
{
	t_cursor	*new;
	int			i;

	new = create_cursor(0, find_adress(cursor->pos + addr));
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = cursor->reg[i];
	new->carry = cursor->carry;
	new->last_live = cursor->last_live;
	return (new);
}

void		init_cursor(t_cor *cor)
{
	int			id;
	uint32_t	pos;
	t_cursor	*tmp;

	id = -1;
	pos = 0;
	while (++id < cor->count_heroes)
	{
		tmp = create_cursor(id, pos);
		tmp->next = cor->cursor;
		cor->cursor = tmp;
		cor->cursors++;
		pos += MEM_SIZE / cor->count_heroes;
	}
}

void		init_game(t_cor *cor)
{
	int			id;
	uint32_t	pc;

	id = 0;
	pc = 0;
	while (id < cor->count_heroes)
	{
		ft_memset(&(cor->field[pc]), id + 1, (size_t)(cor->heroes[id].size));
		ft_memcpy(&(cor->stage[pc]), cor->heroes[id].code,
			(size_t)(cor->heroes[id].size));
		pc += MEM_SIZE / cor->count_heroes;
		id++;
	}
	if (cor->visual == 1)
	{
		cor->aff = 0;
		cor->dump_cycle = -1;
		cor->log = 0;
	}
	cor->last_alive = cor->count_heroes - 1;
	init_cursor(cor);
}
