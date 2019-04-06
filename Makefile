# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 14:55:38 by ybuhai            #+#    #+#              #
#    Updated: 2019/04/06 12:56:12 by akorobov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
ASM			=	asm_name

LIB			=	libftprintf/
LIB_N		=	libftprintf.a

SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
INC_DIR 	= ./includes/
ASM_DIR		= ./asm/

SRC			=	main.c \
				read_flags.c \
				function_for_help.c \
				set_players.c \
				init_game.c \
				validate_heroes.c \
				print_function.c \
				full_game.c \
				read_argtype.c \
				check_who_die.c \
				vs_init.c \
				vs_dinit_win.c \
				vs_control_arena.c \
				vs_key.c \
				vs_sound_die.c \
				vs_winner.c \
				vs_up_statusbar.c \
				vs_init_status_bar.c \
				ftoa.c \
				operation0.c \
				operation5.c \
				operation10.c \
				operation16.c 


LIBFT 		= $(LIBFT_DIR)libftprintf.a
LIBFT_DIR 	= ./libftprintf/
LIBFT_INC	= $(LIBFT_DIR)

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC_FLAGS	= -O3 -Wall -Wextra -Werror
CC 			= gcc


all: $(ASM) $(NAME) 

$(ASM):
	@make -C $(ASM_DIR)
	
$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) -lncurses
	@printf "\033[1;32mcorewar created \033[0m\n"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	@$(CC) -c  $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS) $(DEBUG) 

$(LIBFT):
	@make -C $(LIBFT_DIR)


clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(ASM_DIR)
	@printf "\033[1;33mobject deleted \033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(ASM_DIR)
	@printf "\033[1;31mcorewar deleted \033[0m\n"

re: fclean all

.PHONY: all clean fclean re
