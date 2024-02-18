CC = cc
NAME = exe_shell
SRC = exe_shell.c ft_split.c
CFLAGS = -Wall -Wextra
LDFLAGS = -lreadline

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

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
