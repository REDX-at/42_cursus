CC = gcc
CFLAGS = -Wall -Wextra 

SRC_FILES = ft_atoi.c ft_c.c ft_d.c ft_printf.c ft_s.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIBRARY = libtools.a
TARGET = Tools

all: $(LIBRARY)

$(LIBRARY): $(OBJ_FILES)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(LIBRARY) $(OBJ_FILES)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re