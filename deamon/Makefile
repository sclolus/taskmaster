NAME= deamon
SRC= srcs/main.c \
	srcs/ft_start_deamon.c \
	srcs/ft_accept_connection.c \
	srcs/ft_create_listening_socket.c \
	srcs/ft_create_mem_block.c \
	srcs/ft_mem_block_push_back_elem.c \
	srcs/ft_log.c \
	srcs/ft_fork_instance.c \
	srcs/ft_manage_connection.c \
	srcs/ft_create_control_fork.c \
	srcs/ft_control_process.c \
	srcs/ft_launch_process.c \
	srcs/ft_get_process_status.c \
	srcs/ft_sock_send.c \
	srcs/ft_set_deamon_signals.c \
	srcs/ft_set_control_process_signals.c \
	srcs/ft_update_process_status.c \
	srcs/ft_restart_process.c \
	srcs/ft_stop_process.c \
	srcs/ft_send_status.c \
	srcs/ft_reload_routine.c \
	srcs/ft_signal.c \
	srcs/ft_mark_instance.c \
	srcs/ft_get_instances.c \
	srcs/ft_get_status_str.c \
	srcs/ft_task_execution.c \
	srcs/ft_start_process.c \
	srcs/ft_stop_process.c \
	srcs/ft_kill_deamon.c \
	srcs/ft_instance_exit.c \
	srcs/conf_file_parsing/ft_dump_t_supervised_program.c \
	srcs/conf_file_parsing/ft_get_autorestart.c \
	srcs/conf_file_parsing/ft_get_autostart.c \
	srcs/conf_file_parsing/ft_is_prog_name_case.c \
	srcs/conf_file_parsing/ft_get_cmd.c \
	srcs/conf_file_parsing/ft_get_nbr_procs.c \
	srcs/conf_file_parsing/ft_get_parsing_path.c \
	srcs/conf_file_parsing/ft_get_prog_name.c \
	srcs/conf_file_parsing/ft_get_start_retries.c \
	srcs/conf_file_parsing/ft_get_start_time.c \
	srcs/conf_file_parsing/ft_get_stderr_redirec.c \
	srcs/conf_file_parsing/ft_get_stdout_redirec.c \
	srcs/conf_file_parsing/ft_get_stop_signal.c \
	srcs/conf_file_parsing/ft_get_stop_time.c \
	srcs/conf_file_parsing/ft_get_working_dir.c \
	srcs/conf_file_parsing/ft_parse_conf_file.c \
	srcs/conf_file_parsing/ft_parse_one_line.c \
	srcs/conf_file_parsing/ft_parse_one_prog.c \
	srcs/conf_file_parsing/ft_skip_cmd_header.c \
	srcs/conf_file_parsing/ft_skip_one_line.c \
	srcs/conf_file_parsing/ft_skip_one_prog.c

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
