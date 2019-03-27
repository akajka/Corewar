/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:37:48 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/27 16:33:50 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	find_place_for_hero(t_cor *cor, char *str)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (!cor->heroes[i].file)
		{
			cor->heroes[i].file = str;
			cor->count_heroes++;
			return ;
		}
	}
}

void	add_players_without_numbers(t_cor *cor)
{
	t_files *tmp;
	int		i;
	int		flag;

	tmp = cor->list;
	while (tmp)
	{
		if (tmp->id == 0)
			find_place_for_hero(cor, tmp->file);
		tmp = tmp->next;
	}
	i = -1;
	flag = 0;
	while (++i < MAX_PLAYERS)
	{
		if (cor->heroes[i].file == NULL)
			flag++;
		if (cor->heroes[i].file && flag)
			error_case(USAGE);
	}
}

void	set_players(t_cor *cor)
{
	int		i;
	t_files	*tmp;

	if (!cor->list)
		error_case(USAGE);
	i = MAX_PLAYERS + 1;
	while (--i > 0)
	{
		tmp = cor->list;
		while (tmp)
		{
			if (tmp->id == i)
			{
				if (!cor->heroes[tmp->id - 1].file)
				{
					cor->heroes[tmp->id - 1].file = tmp->file;
					cor->count_heroes++;
				}
				else
					error_case(USAGE);
			}
			tmp = tmp->next;
		}
	}
	add_players_without_numbers(cor);
}
