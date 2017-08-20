NAME= deamon
SRC= srcs/main.c
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
