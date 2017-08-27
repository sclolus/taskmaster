NAME= lexer
CC= gcc
FLAGS= -Wall -Wextra -Werror -fsanitize=address
SRC = 	history.c \
		line.c \
		set_mode.c \
		termcaps.c \
		cursor.c \
		string.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) $^ -I../libft/includes -I. -c
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all
