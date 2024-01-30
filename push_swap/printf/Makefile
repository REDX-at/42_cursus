SRCS =  ft_c.c ft_d.c ft_p.c ft_s.c ft_u.c ft_x.c ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = cc
HEAD = ft_printf.h
CFLAGS = -Wall -Wextra 
NAME = libftprintf.a
RM = rm -f
LIBC = ar rcs

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

all: @$(NAME)

%.o: %.c $(HEAD)
	@echo "\033[92m√\033[0m \033[97m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean



