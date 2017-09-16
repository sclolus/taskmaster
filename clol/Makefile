NAME= 42sh
CC= gcc
FLAGS= -Wall -Werror -Wextra
SRC= srcs/minishell.c \
	srcs/ft_init_shell.c \
	srcs/ft_get_shell_parser.c \
	srcs/ft_signal.c \
	srcs/ft_signal_handlers.c \
	srcs/ft_find_command.c \
	srcs/ft_built_in_echo.c \
	srcs/ft_built_in.c \
	srcs/ft_built_in_cd.c \
	srcs/ft_built_in_cd2.c \
	srcs/ft_built_in_cd3.c \
	srcs/ft_built_in_exit.c \
	srcs/ft_built_in_env.c \
	srcs/ft_built_in_env_utilities.c \
	srcs/ft_built_in_setenv.c \
	srcs/ft_built_in_unsetenv.c \
	srcs/ft_built_in_unset.c \
	srcs/ft_built_in_export.c \
	srcs/ft_shenv.c \
	srcs/ft_env.c \
	srcs/ft_var_attr.c \
	srcs/ft_env.c \
	srcs/ft_lsttotab_token.c \
	srcs/ft_is_quoted.c \
	srcs/ft_line_continuation.c \
	srcs/ft_expansions.c \
	srcs/ft_var_expansion.c \
	srcs/ft_quote_removal.c \
	srcs/ft_expansions_cmd_prefix.c \
	srcs/ft_expansions_cmd_postfix.c \
	srcs/ft_expansions_io_redirect.c \
	srcs/ft_last_return_value_expansion.c \
	srcs/ft_last_return_value.c \
	srcs/ft_exec_command.c \
	srcs/ft_exec_parser.c \
	srcs/ft_exec_pipeline.c \
	srcs/ft_create_pipeline.c \
	srcs/ft_exec_simple_cmd.c \
	srcs/ft_process.c \
	srcs/ft_error.c \
	srcs/ft_redirection.c \
	srcs/ft_free_strsplit.c \
	srcs/ft_redirections_input.c \
	srcs/ft_redirections_output.c \
	srcs/ft_redirections_duplicating.c \
	srcs/ft_heredocs.c \
	srcs/ft_create_heredocs.c \
	srcs/ft_free_heredocs.c \
	srcs/ft_get_cmd_heredoc_count.c \
	srcs/ft_get_heredocs.c \
	srcs/ft_heredocs_redirection.c \
	srcs/ft_check_file.c \
	srcs/ft_check_file_existence.c \
	srcs/ft_get_bin_path.c \
	srcs/ft_argv.c \
	srcs/ft_get_argv.c \
	srcs/ft_lexer.c \
	srcs/ft_lexer_token_list.c \
	srcs/ft_fix_tokens.c \
	srcs/ft_refresh_t_tokens.c \
	srcs/ft_free_tokens.c \
	srcs/ft_get_tokens.c \
	srcs/ft_get_shenv.c \
	srcs/ft_checksum.c \
	srcs/ft_free_strsplit.c \
	srcs/ft_create_watcher.c \
	srcs/ft_watcher.c \
	srcs/ft_update_read_on_socket.c \
	termcaps/termcaps.c \
	termcaps/ft_termgets_utils.c \
	termcaps/ft_current_prompt.c \
	termcaps/ft_line_attributes.c \
	termcaps/ft_get_current_prompt_len.c \
	termcaps/ft_termget_buf_setup.c \
	termcaps/ft_paste_line.c \
	termcaps/line.c \
	termcaps/line_2.c \
	termcaps/history.c \
	termcaps/set_mode.c \
	termcaps/cursor.c \
	termcaps/string.c \
	termcaps/ft_set_term.c \
	termcaps/ft_set_state.c \
	termios_handler/ft_reset_mode.c \
	termios_handler/ft_set_mode.c \
	termios_handler/ft_unset_mode.c \
	parser/ast/ast.c \
	parser/ast/ft_assign_parsers.c \
	parser/ast/ft_dup_parser/ft_dup_parser.c \
	parser/ast/ft_eval_parser.c \
	parser/ast/ft_eval_parser_chars.c \
	parser/ast/ft_eval_parser_logical.c \
	parser/ast/ft_eval_parser_misc.c \
	parser/ast/ft_eval_parser_multiply.c \
	parser/ast/ft_eval_parser_plus.c \
	parser/ast/ft_eval_parser_strings.c \
	parser/ast/ft_eval_parser_str_any_of.c \
	parser/ast/ft_free_parser/ft_free_parser.c \
	parser/ast/ft_free_parser/ft_free_parser_chars.c \
	parser/ast/ft_free_parser/ft_free_parser_logicals.c \
	parser/ast/ft_free_parser/ft_free_parser_misc.c \
	parser/ast/ft_free_parser/ft_free_parser_strings.c \
	parser/ast/ft_get_grammar.c \
	parser/ast/ft_get_grammar_linker.c \
	parser/ast/ft_get_grammar_syntax.c \
	parser/ast/ft_get_parser.c \
	parser/ast/ft_get_parser_chars.c \
	parser/ast/ft_get_parser_grammar.c \
	parser/ast/ft_get_parser_logicals.c \
	parser/ast/ft_get_parser_misc.c \
	parser/ast/ft_get_parser_strings.c \
	parser/ast/ft_get_parser_terminals.c \
	parser/ast/ft_optimizer.c \
	parser/ast/ft_sanitizer/ft_sanitizer.c \
	parser/ast/ft_sanitizer/ft_sanitizer_chars.c \
	parser/ast/ft_sanitizer/ft_sanitizer_logicals.c \
	parser/ast/ft_sanitizer/ft_sanitizer_misc.c \
	parser/ast/ft_sanitizer/ft_sanitizer_strings.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens_chars.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens_logicals.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens_multiply.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens_plus.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens_misc.c \
	parser/ast/ft_eval_tokens/ft_eval_tokens_strings.c \
	completion/ft_completion_add_directory.c \
	completion/ft_free_completion.c \
	completion/ft_get_command_bin_completions_tab.c \
	completion/ft_get_command_directory_completions_tab.c \
	completion/ft_get_completions.c \
	completion/ft_get_completions_tab.c \
	completion/ft_get_max_common_len.c \
	completion/ft_get_max_completion.c \
	completion/ft_lsttotab_completion.c \
	completion/ft_merge_lists.c \
	completion/ft_completion_add_directory_bin.c \
	completion/ft_put_completions.c \
	completion/ft_complete_command.c \
	completion/ft_complete_argv.c \
	completion/ft_fuk_norminette.c \
	completion/ft_termcaps_completion.c \
	completion/ft_sanitize_completion.c \
	../socket/srcs/ft_create_socket.c \
	../socket/srcs/ft_wait_connection.c \
	../socket/srcs/ft_write_socket.c \
	../socket/srcs/ft_select_socket.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./includes
LIBFT_PATH= ../includes

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft
	$(CC) $^ -L../libft -I$(LIBFT_PATH) -lft -ltermcap $(FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $< -I$(HDR_PATH) -I$(LIBFT_PATH)  -I../socket/includes $(FLAGS) -o $@ -c

clean:
	make -C ../libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ../libft fclean
	rm -f $(NAME)

re: fclean all
