NAME = philo
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf
OBJS_DIR = objs/

ifdef DEBUG_MODE
    CFLAGS += -DDEBUG_MODE=$(DEBUG_MODE) -fsanitize=thread 
endif

ifdef PHILO_MAX
    CFLAGS += -DPHILO_MAX=$(PHILO_MAX)
endif


SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c philo.h
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean :
	@$(RM) $(OBJS)

fclean : clean
	@echo "\033[0m \033[97mObject Full Cleaned \033[92m√"
	@$(RM) $(NAME)

BOLD_CYAN=\033[1;36m
RESET_COLOR=\033[0m

.PHONY : clean fclean re all bonus
