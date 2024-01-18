NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra
SRC = push_swap.c swap_utils.c arg_handlers.c sort_list.c sort_three_instruction.c min_max.c

LIBFT = ./libftt/libft.a
PRINTF = ./printf/libftprintf.a

OBJS = $(SRC:.c=.o)

all: make_libft make_printf $(NAME)
	@echo "\033[0m \033[97mCompile Done \033[92m√"

make_libft:
	@cd ./libftt && make > /dev/null

make_printf:
	@cd ./printf && make > /dev/null

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $^ -o $@

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0m \033[97mObject files Cleaned \033[92m√"
	@rm -f $(OBJS)

fclean: 
	@echo "\033[0m \033[97mObject Full Cleaned \033[92m√"
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@cd ./libftt && make fclean > /dev/null
	@cd ./printf && make fclean > /dev/null

re: clean fclean all