C = clang
NAME = asm
FLAGS = -Wall -Werror -Wextra
DIR_S = src
HEADER = include
DIR_O = obj
LIBFT = libft
SOURCE = main.c \
	asm_parser.c \
	asm_header_handler.c \
	check_line.c \
	check_arguments.c \
	write.c \
	write_args.c \
	write_opcode.c \
	join_line.c \
	disasm.c \
	disasm_args.c \
	disasm_arg_handler.c \
	make_name_com.c 

SRCS = $(addprefix $(DIR_S)/,$(SOURCE))
OBJS = $(addprefix $(DIR_O)/,$(SOURCE:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libftprintf.a .
	@gcc $(FLAGS) $(OBJS) libftprintf.a -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f libftprintf.a
	@make fclean -C $(LIBFT)

re: fclean all
