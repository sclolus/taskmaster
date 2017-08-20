NAME= deamon
SRC= srcs/main.c \
	srcs/ft_accept_connection.c \
	srcs/ft_create_listening_socket.c \
	srcs/ft_create_mem_block.c \
	srcs/ft_mem_block_push_back_elem.c \
	srcs/ft_log.c \
	srcs/ft_fork_instance.c \
	srcs/ft_manage_connection.c \
	srcs/ft_sock_send.c \
	srcs/ft_set_deamon_signals.c \
	srcs/ft_mark_instance.c \
	srcs/ft_get_instances.c \
	srcs/ft_get_status_str.c
#	srcs/ft_map_sockets.c \
	srcs/ft_pong.c \p

OBJ= $(SRC:.c=.o)
HDR_PATH= ../libft/includes/
CC= gcc
CC_FLAGS= -v -Weverything -Wall -Werror -Wextra -g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt
LFT_PATH= ../libft/
#VPATH=./srcs:./obj:./includes/

all: submodule $(NAME)

submodule:
	@make -C $(LFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ -L$(LFT_PATH) -lft -o $(NAME)
%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -I../includes -o $@

clean:
	rm -f $(OBJ)
	make -C $(LFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LFT_PATH) fclean

re: fclean all
