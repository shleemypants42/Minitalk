Name = server
Name2 = client

SERVER_FILES = server.c
CLIENT_FILES = client.c

SERVER_OBJS = $(SERVER_FILES:.c=.o)
CLIENT_OBJS = $(CLIENT_FILES:.c=.o)

CFLAGS = -Wextra -Werror -Wall

CC = gcc

all: $(Name) $(Name2)

$(Name): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o server

$(Name2): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o client

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:	clean
	rm -f server client

re:  fclean all
.PHONY: all clean fclean re