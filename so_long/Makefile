NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKER = -lmlx -framework OpenGL -framework AppKit
SRC = so_long.c
OBJS = $(SRC:.c=.o)

all: $(NAME)
	@echo "\033[0m \033[97mCompile Done \033[92m√"

$(NAME): $(OBJS)
	@$(CC) $(LINKER) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0m \033[97mObject files Cleaned \033[92m√"
	@rm -f $(OBJS)

fclean: 
	@echo "\033[0m \033[97mObject Full Cleaned \033[92m√"
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: clean fclean all