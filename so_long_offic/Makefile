NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKER = -lmlx -framework OpenGL -framework AppKit
SRC = so_long.c ./utils/args_handler.c ./utils/check_mapber.c ./utils/check_map.c \
	./utils/get_line_double.c ./utils/get_map.c ./utils/set.c \
	./utils/ft_strleny.c ./utils/ft_strjoiny.c ./utils/ft_strdupy.c \
	 ./get_next_line/get_next_line.c \
	 ./get_next_line/get_next_line_utils.c \
	./utils/fill_maps.c ./utils/ft_l_split.c \
	 ./utils/second_check.c ./utils/check_third.c ./utils/the_renders.c \
	 ./utils/render_move_me.c \
	 ./utils/utils_move_player.c

LIBFT = ./libftt/libft.a
PRINTF = ./printf/libftprintf.a

OBJS = $(SRC:.c=.o)

all: make_libft make_printf $(NAME)
	@echo "\033[0m \033[97mCompile Done \033[92m√"

make_libft:
	@cd ./libftt && make > /dev/null

make_printf:
	@cd ./printf && make > /dev/null

$(NAME): $(OBJS)
	@$(CC) $(LIBFT) $(PRINTF) $(LINKER) $^ -o $@

%.o: %.c so_long.h
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