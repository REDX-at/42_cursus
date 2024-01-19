NAME = push_swap_bonus
CC = cc 
CFLAGS = -Wall -Wextra
BONUS = checker.c arg_handlers_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		swap_utils_bonus.c swap_utils_thr_bonus.c swap_utils_two_bonus.c utils_bonus.c

LIBFT = ../libftt/libft.a
PRINTF = ../printf/libftprintf.a

OBJS = $(BONUS:.c=.o)

bonus: make_libft make_printf $(NAME)
	@echo "\033[0m \033[97mCompile Done \033[92m√"

make_libft:
	@cd ../libftt && make > /dev/null

make_printf:
	@cd ../printf && make > /dev/null

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $^ -o $@

%.o: %.c push_swap_bonus.h
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
	@cd ../libftt && make fclean > /dev/null
	@cd ../printf && make fclean > /dev/null

re: clean fclean bonus