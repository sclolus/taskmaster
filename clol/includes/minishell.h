/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 22:56:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/20 07:38:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/signal.h>
# include <dirent.h>
# include <signal.h>
# include <stdlib.h>
# include "termcaps.h"
# include "termios_handler.h"
# include "ft_completion.h"
# include "ft_new_completion.h"
# include "ast.h"

# define SHELL_NAME "42sh: "
# define GRAMMAR_CHECKSUM 2027082

# define CHARSET_SPECIAL_CHAR "|&<>;*?"
# define CHARSET_SPECIAL_DELIMITORS "(|&<>; )"
# define CHARSET_LOGICAL "&|"
# define CHARSET_END_OF_EXPRESSION " ;"
# define ESCAPE_CHAR "\\"
# define CHARSET_VAR_NAME "_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
# define CHARSET_OP "|&;<>"
# define CHARSET_WHITESPACES " \t\n"

# define CHARSET_QUOTES "'\""
# define CHARSET_ESCAPE_BCKSLH "$`\"\\\n"
# define QUOTE_REMOVAL_BUFF_SIZE 256

# define MAX_PATH_NAME 4096
# define MAX_FILE_NAME 255
# define MAX_PATH 4096
# define MAX_VAR_NAME 1024

# define EXIT_NO_PERM 126
# define EXIT_ILLEGAL_CMD 127
# define EXIT_REDIREC_ERROR 55
# define EXIT_SIG_ERROR 11
# define EXIT_VAR_NOT_FOUND 56
# define EXIT_HEREDOC_FILE 57

# define POSIX_EXIT_STATUS(x) (x % 0xFF)

# define BUILT_IN_COUNT 9

# define ERROR_BAD_FD "Bad file descriptor"
# define ERR_PERM_DENIED "Permission denied: "
# define ERR_ILL_CMD "Command not found: "
# define ERR_MALLOC "Internal memory management failed at: "
# define ERR_NOFILE "No such file or directory: "

typedef uint8_t	t_bool;
typedef struct		s_heredoc
{
	char			*filename;
	char			*delimiter;
}					t_heredoc;

typedef struct		s_shenv
{
	struct s_env	*env;
	char			**var;
	t_bool			*attr;
	uint32_t		count;
	t_list			*heredocs;
	uint32_t		heredocs_index;
}					t_shenv;

typedef struct		s_built_in
{
	char			*id;
	int32_t			(*f)(char **, t_shenv*);
}					t_built_in;

typedef struct		s_env
{
	char			**env;
	uint32_t		variable_count;
}					t_env;

typedef struct		s_process
{
	struct s_process	*next;
	struct s_process	*prev;
	pid_t				pid;
	pid_t				gpid;
	char				**argv;
}					t_process;

typedef struct		s_job
{
	struct s_job		*next;
	t_parser			*cmd;
	struct s_process	*processes;
	pid_t				pgid;
}					t_job;

typedef struct		s_shell
{
	struct termios	backup_term;
	int				terminal;
	int				interactive;
	pid_t			shell_pgid;
}					t_shell;

t_shell				*g_shell;

int32_t				ft_setup_sighandlers(void);
void				ft_init_shell(void);

char				*ft_find_command(char *filename, char **path);
int32_t				ft_is_unbalanced(char *line);
char				*ft_line_continuation(char *line);
int32_t				ft_is_line_backslash_terminated(char *line);

char				*ft_variable_expansion(char *token, char **env);

char				*ft_find_env(char const **env, char const *variable);
char				*ft_strjoin_f(char *a, char *b, int32_t mode);

uint32_t			ft_is_escaped(char *input, uint32_t index);
uint32_t			ft_is_quoted(char *input, uint32_t index);

t_parser			*ft_get_shell_parser(void);
uint64_t			ft_checksum(char *string);

char				**ft_get_env_value(char **env, char *variable);

/*
** Lexer
*/

char				**ft_lexer(char *input);
t_tokens			*ft_get_tokens(char *input);
void				ft_put_tokens(char **tokens);
uint32_t			ft_get_tokens_count(char **tokens);
void				ft_free_tokens(t_tokens *tokens);
void				ft_add_token_to_list(t_list **token_list
									, char *input, uint32_t start, uint32_t i);
char				**ft_token_list_to_tab(t_list *token_list);
void				ft_fix_tokens(t_tokens *tokens);
void				ft_refresh_t_tokens_tokens(t_tokens *tokens, uint32_t index
									, uint32_t token_count);
void				ft_refresh_t_tokens_lens(t_tokens *tokens, uint32_t index
									, char *ptr, uint32_t token_count);

/*
** redirections
*/

typedef int32_t	(*t_redirec)(t_parser*);

int32_t				ft_redirections(t_parser *redirect);
int32_t				ft_output_redirect(t_parser *redirect);
int32_t				ft_output_append_redirect(t_parser *redirect);
int32_t				ft_duplicating_input_redirect(t_parser *redirect);
int32_t				ft_duplicating_output_redirect(t_parser *redirect);
int32_t				ft_input_redirect(t_parser *redirect);
int32_t				ft_read_write_redirect(t_parser *redirect);

/*
** Heredocs
*/

int32_t				ft_heredoc_redirect(t_parser *heredoc);
void				ft_create_heredocs(t_tokens *tokens, t_shenv *shenv);
int					ft_open_heredoc_file(char *filename);
char				*ft_get_heredoc_delimiter_index(t_tokens *tokens
													, uint32_t index);
int					ft_get_heredoc_index(uint32_t index, t_shenv *shenv);
t_heredoc			*ft_get_heredoc_pointer(uint32_t index, t_shenv *shenv);
void				ft_clear_heredoc(t_list *heredoc);
void				ft_put_heredocs(t_shenv *shenv);
void				ft_get_heredoc(t_heredoc *heredoc, t_shenv *shenv);
void				ft_get_heredocs(t_shenv *shenv);
void				ft_put_heredocs_content(t_shenv *shenv);
void				ft_clear_heredocs(t_shenv *shenv);
uint32_t			ft_get_cmd_heredoc_count(t_parser *simple_cmd);
void				ft_delone_heredoc(t_shenv *shenv);
t_heredoc			*ft_get_t_heredoc_index(uint32_t index, t_shenv *shenv);

/*
** expansions
*/

int32_t				ft_expansions(t_parser *simple_cmd, t_shenv *env);
void				ft_var_expansion(char **word, t_shenv *shenv);
void				ft_quote_removal(char **word);
void				ft_tilde_expansion(char **word, t_shenv *env);
int32_t				ft_find_file(char *filename, t_env *env);
char				*ft_get_file_name(char *file);
char				*ft_get_path_name(char *file);
void				ft_expansions_cmd_prefix(t_parser *cmd_prefix
										, t_shenv *shenv);
void				ft_expansions_cmd_postfix(t_parser *cmd_postfix
										, t_shenv *shenv);
void				ft_expansions_io_filename(t_parser *io_filename
										, t_shenv *shenv);
void				ft_expansions_io_number(t_parser *io_number
										, t_shenv *shenv);
void				ft_expansions_io_redirect(t_parser *io_redirect
										, t_shenv *shenv);
void				ft_expansions_io_file(t_parser *io_file
										, t_shenv *shenv);
uint32_t			*ft_get_last_return_value(void);
void				ft_last_return_value_expansion(char **word);

/*
** built_ins
*/

int32_t				ft_built_in_echo(char **argv, t_shenv *shenv);
int32_t				ft_built_in(char **argv, t_shenv *shenv);
int32_t				ft_built_in_cd(char **argv, t_shenv *shenv);
int32_t				ft_built_in_history(char **argv, t_env *env);
int32_t				ft_built_in_exit(char **argv, t_shenv *shenv);
int32_t				ft_built_in_setenv(char **argv, t_shenv *shenv);
int32_t				ft_built_in_env(char **argv, t_shenv *shenv);
int32_t				ft_built_in_print_env(t_shenv *shenv);
void				ft_built_in_exec_env_cmd(char **argv
									, t_shenv *shenv, t_shenv *exec_env);
t_shenv				*ft_modify_env(char **argv, uint32_t count, t_shenv *shenv);
t_shenv				*ft_create_new_shenv(char **argv
									, uint32_t count);
int32_t				ft_built_in_unsetenv(char **argv, t_shenv *shenv);
int32_t				ft_built_in_export(char **argv, t_shenv *shenv);
int32_t				ft_built_in_unset(char **argv, t_shenv *shenv);
int32_t				ft_cd_set_oldpath(t_shenv *shenv);
char				ft_cdpath_search(t_string *curpath, char *op
									, t_shenv *shenv);
int32_t				ft_create_path(t_string *dst, char *path, char *op);
int32_t				ft_get_pwd(t_string *curpath, t_shenv *shenv);
int32_t				rst_tstring(t_string *str);
int32_t				ft_check_chdir(t_string *curpath, char *arg, char *cwd
									, t_shenv *shenv);
/*
** Error handling
*/

void				ft_error_exit(uint32_t n, char **str, int32_t exit_status);
int32_t				ft_error(uint32_t n, char **str, int32_t return_status);

/*
** Permissions/files checks
*/

int32_t				ft_check_exec_perm(char *pathname);
int32_t				ft_check_exec_read(char *pathname);
int32_t				ft_check_exec_write(char *pathname);
int32_t				ft_is_dir(char *pathname);
int32_t				ft_check_file(char *filename);
char				*ft_get_bin_path(char *pathname, char *filename);

/*
** Shell environnement management
*/

t_shenv				*ft_init_shenv(uint32_t argc, char **env);
t_shenv				**ft_get_shenv(void);
char				*ft_find_env(char const **env, char const *variable);
t_env				*ft_get_env(t_shenv *shenv);
char				**ft_find_var(t_shenv *shenv, char *var);
int32_t				ft_shenv_get_env_count(t_shenv *shenv);
uint32_t			ft_get_env_count(char **env);

t_bool				ft_is_var_exported_index(t_shenv *shenv, uint32_t index);
t_bool				ft_is_var_exported(t_shenv *shenv, char *var);
t_bool				ft_set_var_to_export(t_shenv *shenv, char *var);

void				ft_modify_var(t_shenv *shenv, char *var);
void				ft_add_var(t_shenv *shenv, char *var);
int32_t				ft_unset_var(t_shenv *shenv, char *var);

void				ft_free_t_env(t_env *env);
void				ft_free_t_shenv(t_shenv *shenv);
void				ft_free_t_shell(void);

/*
** Signal Handling
*/

int32_t				ft_setup_sighandlers(void);
void				ft_reset_signals(void);
void				ft_ignore_signals(void);
void				ft_handler_int(int signum);
void				ft_handler_tstp(int signum);
void				ft_handler_cont(int signum);

/*
** Miscellaneous Free functions
*/

void				ft_free_argv(char **argv);
void				ft_free_strsplit(char **split);

/*
** Processes
*/

void				ft_clear_processes(t_process **processes);
void				ft_t_process_print(t_process *process);
void				ft_put_processes_in_foreground(t_process *process
											, int cont);

/*
** Term setup
*/

int32_t				ft_unset_term(void);
int32_t				ft_set_term(void);
int32_t				ft_unset_echo_mode(void);
int32_t				ft_set_echo_mode(void);
int32_t				ft_set_canonical_mode(void);
int32_t				ft_unset_echoctl_mode(void);

/*
** Shell utilities
*/

void				ft_put_shell_in_foreground(void);
void				ft_init_shell(void);
void				ft_exit_shell(int exit_status);

/*
** Execution
*/

char				**ft_get_argv(t_parser *simple_cmd);
int32_t				ft_is_built_in(t_parser *parser);
t_process			*ft_start_process(t_parser *simple_cmd, pid_t gpid
											, int *stdfd, t_shenv *shenv);
t_process			*ft_t_process_add(t_process **processes, t_process *new);
int32_t				ft_exec_pipeline(t_parser *parser, t_shenv *shenv);
int32_t				ft_exec_pipe_sequence(t_parser *parser, t_shenv *shenv);
t_process			*ft_create_pipeline(t_parser *pipe_sequence
										, t_shenv *shenv);
int32_t				ft_exec_list(t_parser *parser, t_shenv *shenv);
int32_t				ft_exec_and_or(t_parser *parser, t_shenv *shenv);
int32_t				ft_exec_env_assignment(t_parser *parser, t_shenv *shenv
										, t_bool set_to_export);
int32_t				ft_exec_cmd_prefix(t_parser *cmd_prefix, t_shenv *shenv
										, t_bool set_to_export);
void				ft_exec_cmd(char **argv, t_shenv *shenv);
int32_t				ft_exec_simple_cmd(t_parser *simple_cmd, t_shenv *shenv);
int32_t				ft_exec_command(t_parser *parser, t_shenv *shenv);

#endif
