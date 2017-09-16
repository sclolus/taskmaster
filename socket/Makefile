NAME= libsocket.a
CC= gcc
FLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address -fsanitize-blacklist=../deamon/my_ignores.txt
SRC=	srcs/ft_create_socket.c \
		srcs/ft_select_socket.c \
		srcs/ft_sock_log.c \
		srcs/ft_wait_connection.c \
		srcs/ft_write_socket.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./includes
LIBFT_PATH= ../libft/
LIBFT_HDR= ../libft/includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -I$(HDR_PATH) -I$(LIBFT_HDR) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
