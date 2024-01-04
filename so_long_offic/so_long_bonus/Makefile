NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKER = -lmlx -framework OpenGL -framework AppKit
SRC = so_long_bonus.c ./utils_bonus/args_handler_bonus.c ./utils_bonus/check_mapber_bonus.c ./utils_bonus/check_map_bonus.c \
	./utils_bonus/get_line_double_bonus.c ./utils_bonus/get_map_bonus.c ./utils_bonus/set_bonus.c \
	./utils_bonus/ft_strleny_bonus.c ./utils_bonus/ft_strjoiny_bonus.c ./utils_bonus/ft_strdupy_bonus.c \
	 ./get_next_line/get_next_line.c \
	 ./get_next_line/get_next_line_utils.c \
	./utils_bonus/fill_maps_bonus.c ./utils_bonus/ft_l_split_bonus.c \
	 ./utils_bonus/second_check_bonus.c ./utils_bonus/check_third_bonus.c ./utils_bonus/the_renders_bonus.c \
	 ./utils_bonus/render_move_me_bonus.c ./utils_bonus/show_move_bonus.c ./utils_bonus/enemie_bonus.c \
	 ./utils_bonus/utils_move_player_bonus.c

LIBFT = ./libftt/libft.a
PRINTF = ./printf/libftprintf.a

OBJS = $(SRC:.c=.o)

bonus: make_libft make_printf $(NAME)
	@echo "\033[0m \033[97mCompile Done \033[92m√"

make_libft:
	@cd ./libftt && make > /dev/null

make_printf:
	@cd ./printf && make > /dev/null

$(NAME): $(OBJS)
	@$(CC) $(LIBFT) $(PRINTF) $(LINKER) $^ -o $@

%.o: %.c so_long_bonus.h
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

re: clean fclean bonus