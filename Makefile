# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 14:55:38 by ybuhai            #+#    #+#              #
#    Updated: 2019/03/27 15:40:33 by ybuhai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

LIB			=	libftprintf/
LIB_N		=	libftprintf.a

SRC_D		=	src/
SRC			=	$(SRC_D)main.c \
				$(SRC_D)read_flags.c \
				$(SRC_D)error_case.c \
				$(SRC_D)function_for_help.c \
				$(SRC_D)set_players.c \

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

INCLUDE		=	-I includes/
CFLAGS		=	-g3 -O0
C			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(C) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)$(LIB_N) $(INCLUDE)

$(OBJ): $(OBJ_D)

$(OBJ_D):
	@mkdir -p $(OBJ_D)$(SRC_D)

$(OBJ_D)%.o: %.c
	@$(C) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)
	@rm -rf $(OBJ_D)

re: fclean all

.PHONY: all clean fclean re
