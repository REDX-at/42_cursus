CC = cc
CFLAGS = -Wall -Wextra -pedantic
LIBFTPRINTF_PATH = libftprintf.a

all: server client

server: server.c
	$(CC) $(CFLAGS) server.c $(LIBFTPRINTF_PATH) -o server

client: client.c
	$(CC) $(CFLAGS) client.c $(LIBFTPRINTF_PATH) -o client

.PHONY: clean

clean:
	rm -f server client

fclean: clean

re: fclean all
