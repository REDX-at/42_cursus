NAME = push_swap
NAME_BONUS = checker
CC = cc 
CFLAGS = -Wall -Wextra 
SRC = push_swap.c swap_utils.c arg_handlers.c sort_list.c sort_three_instruction.c \
	min_max.c swap_utils_two.c swap_utils_three.c utils_turk.c steps_turk.c \
	setup_stack.c
BONUS = checker.c arg_handlers_bonus.c ./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c swap_utils_bonus.c swap_utils_thr_bonus.c \
	swap_utils_two_bonus.c utils_bonus.c utils_two_bonus.c

LIBFT = ./libftt/libft.a
PRINTF = ./printf/libftprintf.a

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

all: make_libft make_printf $(NAME)
	

bonus: make_libft make_printf $(NAME_BONUS)
	

make_libft:
	@cd ./libftt && make

make_printf:
	@cd ./printf && make

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $^ -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(PRINTF)
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) $^ -o $@

%.o: %.c push_swap.h push_swap_bonus.h
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: 
	@echo "\033[0m \033[97mObject Full Cleaned \033[92m√"
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@rm -f $(OBJS_BONUS)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@cd ./libftt && make fclean > /dev/null
	@cd ./printf && make fclean > /dev/null

re: clean fclean all