NAME = philo
CC = cc -fsanitize=address 
CFLAGS = -Wall -Wextra
SRC = philosopher.c utils_philo.c check_args.c ft_atol.c protected_ft.c

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $^ -o $@

%.o: %.c philo.h
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean:
	@echo "\033[0m \033[97mObject Full Cleaned \033[92m√"
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all