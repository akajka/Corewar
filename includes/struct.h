/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:24:17 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 14:28:20 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "corewar.h"

typedef struct		s_cursor
{
	int				id;
	int				carry;
	int				last_live;
	int				pos;
	uint8_t			operation;
	int				cycle_wait;
	int				step;
	uint8_t			args_types[3];
	int				reg[REG_NUMBER];
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_hero
{
	int				id;
	int				size;
	char			*name;
	char			*comment;
	char			*file;
	uint8_t			*code;
	int				live;
	int				last_live;
}					t_hero;

typedef struct		s_files
{
	char			*file;
	int				id;
	struct s_files	*next;
}					t_files;

typedef struct		s_cor
{
	uint8_t			stage[MEM_SIZE];
	uint8_t			field[MEM_SIZE];
	t_hero			heroes[MAX_PLAYERS];
	t_files			*list;
	t_cursor		*cursor;
	ssize_t			cycles;
	ssize_t			cycles_to_die;
	ssize_t			cycles_after_check;
	ssize_t			check_in;
	ssize_t			live_in;
	int				aff;
	int				log;
	int				cursors;
	int				count_heroes;
	int				dump_cycle;
	int				visual;
	int				last_alive;
}					t_cor;

#endif
