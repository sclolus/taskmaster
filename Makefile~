NAME= lem-in
SRC= srcs/main.c \
	srcs/ft_solve.c \
	srcs/ft_put_lines.c \
	srcs/ft_put_solution.c \
	srcs/parsing/ft_parse.c \
	srcs/parsing/ft_get_lem_nbr.c \
	srcs/parsing/ft_get_case.c \
	srcs/parsing/ft_is_case_start.c \
	srcs/parsing/ft_get_last_attr.c \
	srcs/parsing/ft_parsing_actions.c \
	srcs/parsing/ft_get_new_tube.c \
	srcs/parsing/ft_get_new_room.c \
	srcs/parsing/ft_get_new_cmd.c \
	srcs/parsing/ft_get_new_note.c \
	srcs/parsing/ft_get_set_states.c \
	srcs/parsing/ft_check_integrity.c \
	srcs/ft_create_mem_block.c \
	srcs/ft_mem_block_push_back_elem.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Weverything -Wall -Werror -Wextra # -g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt
#VPATH=./srcs:./obj:./includes/

all: submodule $(NAME)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -o $(NAME)
%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
