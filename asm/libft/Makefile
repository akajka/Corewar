# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/05 18:03:05 by ystasiv           #+#    #+#              #
#    Updated: 2019/04/06 12:03:32 by akorobov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror 

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADER = include

SOURCES = parsing.c \
		ft_printf.c \
		other.c \
		get_lenght.c \
		handle_other.c \
		handle_char.c \
		handle_hex.c \
		handle_percent.c \
	 	handle_int.c \
	 	handle_long.c \
	 	handle_octal.c \
	 	handle_ptr.c \
	 	handle_str.c \
	 	handle_uint.c \
	 	handle_wchar.c \
	 	handle_wstr.c 
	 
# DBG MESSAGE
SUCCESS			:=	$(C_GOOD)SUCCESS$(C_NO)
OK				:=	$(C_OK)OK$(C_NO)



SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))


all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c 
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@rm -f libft.a
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
