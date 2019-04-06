/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:57:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/06 12:26:20 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/libftprintf.h"
# include "op.h"
# include "struct.h"
# include "visual.h"
# define ERROR_FILE "Error file"
# define OP_LEN 1
# define ARG_LEN 1
# define REG_LEN 1

void				op_live(t_cor *cor, t_cursor *cursor);
void				op_ld(t_cor *cor, t_cursor *cursor);
void				op_st(t_cor *cor, t_cursor *cursor);
void				op_add(t_cor *cor, t_cursor *cursor);
void				op_sub(t_cor *cor, t_cursor *cursor);
void				op_and(t_cor *cor, t_cursor *cursor);
void				op_or(t_cor *cor, t_cursor *cursor);
void				op_xor(t_cor *cor, t_cursor *cursor);
void				op_zjmp(t_cor *cor, t_cursor *cursor);
void				op_ldi(t_cor *cor, t_cursor *cursor);
void				op_sti(t_cor *cor, t_cursor *cursor);
void				op_fork(t_cor *cor, t_cursor *cursor);
void				op_lld(t_cor *cor, t_cursor *cursor);
void				op_lldi(t_cor *cor, t_cursor *cursor);
void				op_lfork(t_cor *cor, t_cursor *cursor);
void				op_aff(t_cor *cor, t_cursor *cursor);

typedef struct		s_operation
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	int				args_types_code;
	uint8_t			args_types[3];
	int				modify_carry;
	uint8_t			t_dir_size;
	int				cycles;
	void			(*func)(t_cor *, t_cursor *);

}					t_operation;

static				t_operation	g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 1,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
};

static uint8_t			g_arg_code[3] = {
	T_REG,
	T_DIR,
	T_IND
};

void				read_flags(t_cor *cor, int argc, char **argv);
void				error_case(char *str);
int					mod_atoi(char *str);
t_files				*create_list(int i, char *data);
int					is_filename(char *str);
void				add_file(t_cor *cor, int *i, char **argv);
void				set_players(t_cor *cor);
void				validate_heroes(t_cor *cor);
void				init_game(t_cor *cor);
void				full_game(t_cor *cor);
void				read_argtype(t_cor *cor, t_cursor *curs, t_operation *o);
int32_t				find_adress(int32_t i);
void				print_players(t_cor *cor);
void				print_arena(t_cor *cor);
void				print_last_alive(t_cor *cor);
void				print_live(t_cor *cor, int id);
int					validate_args(t_cursor *cursor, t_operation *operation);
int					check_args(t_cursor *cursor, t_cor *cor, t_operation *o);
int					count_step(uint8_t type, t_operation *operation);
int8_t				count_size(t_cor *cor, int pos, int step);
void				next_op(t_cursor *cursor);
void				check_who_die(t_cor *cor);
int					take_op(t_cor *cor, t_cursor *cursor, uint8_t i, int mod);
void				int_to_byte(t_cor *cor, int32_t a, int32_t m, int32_t t);
int32_t				byte_to_int(t_cor *cor, int32_t addr, int32_t size);
t_cursor			*copy_cursor(t_cursor *cursor, int32_t addr);
void				set_field(t_cor *cor, int32_t addr, uint8_t i, int32_t s);
void				print_help(void);

#endif
