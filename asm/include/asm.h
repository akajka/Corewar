/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:18:12 by ystasiv           #+#    #+#             */
/*   Updated: 2019/03/28 18:17:33 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/include/ft_printf.h"
# include "../libft/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALTERNATIVE_COMMENT		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

int g_size;
int g_current_pos;
int g_line;

static const char	*g_etable[] = {"live", "ld", "st", "add", "sub", "and",
	"or", "xor", "zjmp", "ldi", "sti", "fork",
	"lld", "lldi", "lfork", "aff", NULL };

typedef struct		s_label
{
	char			*name;
	unsigned int	pos;
	struct s_label	*next;
}					t_label;

typedef struct		s_asm
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			*filename;
	int				magic;
	int				fd;
	int				new_fd;
}					t_asm;

int					reverse_int(int n, size_t nbytes);
char				*start_parsing(t_asm *s, t_label **labels);
void				ft_error(char *s, int i);
void				make_header(t_asm *s);
int					check_line(char *line);
int					check_type(char *line, int *type);
int					ind(char **line, int type);
int					reg(char **line, int type);
int					dir(char **line, int type, int t);
void				magic_write(int dst, int *buf, size_t len);
int					check_line(char *line);
void				write_file(t_asm *s, char *file, t_label *labels);
void				write_arg_code(int type, char *file, int fd);
char				*join(char *dst, char *line);

int					write_ind(int fd, t_label *l, char **file);
int					write_dir(int fd, t_label *l, char **file, int ty);
int					write_reg(int fd, char **file);
void				make_name(char *str, t_asm *s);
void				make_comment(char *str, t_asm *s);

void				start_disasm(t_asm *s, char *name);
int					rewrite_dir(int ty, int in, int out);
int					rewrite_ind(int input, int output);
int					rewrite_reg(int input, int output);
int					write_arg3(int args, int type, int input, int output);
int					write_arg2(int args, int type, int input, int output);
int					write_arg1(int args, int type, int input, int output);
#endif
