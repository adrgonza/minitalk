NAME = program
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = server.c client.c \

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT)

$(SERVER_BONUS):
	$(CC) $(CFLAGS) server_bonus.c $(LIB) -o $(SERVER_BONUS)

$(CLIENT_BONUS):
	$(CC) $(CFLAGS) client_bonus.c $(LIB) -o $(CLIENT_BONUS)

clean:
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean: clean

re: fclean all

.PHONY: all bonus flean clean re