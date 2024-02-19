CC = cc
NAME = minishell
SRC = minishell.c ./execute/built_in_cmd.c utils.c Exe_file.c
CFLAGS = -Wall -Wextra -fsanitize=address
OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) -lreadline $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[0m \033[97mObject Full Cleaned \033[92m√"
	@rm -f $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "Automatic commit via make push"
	@git push
