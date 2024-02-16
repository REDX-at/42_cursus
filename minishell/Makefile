CC = cc
NAME = exe_shell
SRC = exe_shell.c
CFLAGS = -Wall -Wextra -lreadline
OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all