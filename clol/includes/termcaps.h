/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 03:26:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/14 00:26:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <termios.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <term.h>
# include <stdint.h>
# include "libft.h"
# include "minishell.h"
# include "ft_completion.h"

# undef tab
# define ID_MOVE_START_LINE 0x1
# define ID_MOVE_END_LINE 0x5
# define ID_MOVE_START_LINE_HOME 0x485B1B
# define ID_MOVE_END_LINE_END 0x465B1B
# define ID_MOVE_DOWN_CURSOR 0x425B1B1B
# define ID_MOVE_UP_CURSOR 0x415B1B1B
# define ID_MOVE_PREV_WORD 0x445b1b1b
# define ID_MOVE_NEXT_WORD 0x435b1b1b
# define ID_DELETE_CHAR 0x7F
# define ID_MOVE_LEFT_CURSOR 0x445B1B
# define ID_MOVE_RIGHT_CURSOR 0x435B1B
# define ID_KILL_LINE 0xB
# define ID_YANKING 0x14
# define ID_DIRECTION_KEY 0x5B1B
# define ID_HISTORIC_YANKING 0xA080E2
# define ID_HISTORY_DOWN 0x42
# define ID_HISTORY_UP 0x41
# define ID_TAB 0x9

# define TERMCAPS_WHITESPACES " \t\n"

typedef struct s_env	t_env;
typedef struct s_shenv	t_shenv;
typedef struct s_ltree	t_ltree;

typedef enum		e_termcaps_state
{
	COMPLETION_SHOWN = 0,
	NORMAL = 1,
	COMMAND_NAME = 2,
	ARGV = 3,
}					t_termcaps_state;

# define NORMAL_PROMPT_STATE "$>"
# define S_QUOTE_PROMPT_STATE "quote>"
# define D_QUOTE_PROMPT_STATE "dquote>"
# define LINE_CONT_PROMPT_STATE ">"
# define HEREDOC_CONT_PROMPT_STATE "heredoc>"

# define NORMAL_PROMPT_LEN sizeof(NORMAL_PROMPT_STATE) - 1
# define S_QUOTE_PROMPT_LEN sizeof(S_QUOTE_PROMPT_STATE) - 1
# define D_QUOTE_PROMPT_LEN sizeof(D_QUOTE_PROMPT_STATE) - 1
# define LINE_CONT_PROMPT_LEN sizeof(LINE_CONT_PROMPT_STATE) - 1
# define HEREDOC_CONT_PROMPT_LEN sizeof(HEREDOC_CONT_PROMPT_STATE) - 1

typedef int32_t		(*t_comp_event)(t_string*, t_shenv *);
typedef uint8_t	t_bool;
typedef enum		e_prompt
{
	NORMAL_PROMPT = 0,
	SINGLE_QUOTE = 1,
	DOUBLE_QUOTE = 2,
	LINE_CONTINUATION = 3,
	HEREDOC_PROMPT = 4,
}					t_prompt;

# define NP NORMAL_PROMPT

typedef struct		s_prompt_state
{
	char		*prompt;
	uint32_t	len;
}					t_prompt_state;

typedef struct		s_line_attributes
{
	t_bool	canceled;
	t_bool	multiple_lines;
}					t_line_attributes;

typedef struct		s_term_event
{
	int32_t			id;
	void			(*f)(t_string*);
}					t_term_event;

int32_t				ft_completion(t_string *buf, t_shenv *shenv);
int32_t				ft_put_completions(t_string *buf, char **completions,
								uint32_t n, char *prefix);
int32_t				ft_put_completion(char **completions,
								t_string *buf, char *prefix);
int32_t				ft_complete_argv(t_string *buf, t_shenv *shenv);
int32_t				ft_completion_normal_state(t_string *buf, t_shenv *shenv);
int32_t				ft_complete_command_name(t_string *buf, t_shenv *shenv);
int32_t				ft_put_max_completion(t_string *buf, char **completions
												, char *prefix, uint32_t n);
int					ft_putterm(int c);
void				ft_termcaps_putstr(t_string *buf, char *str);
t_termcaps_state	*ft_get_term_state(void);
void				ft_set_term_state(t_string *buf);
void				ft_put_term_state(t_termcaps_state *state);

int32_t				ft_set_term(void);

int64_t				ft_termget(char **line, t_shenv *shenv);
uint32_t			ft_termget_cleanup(char *tmp, t_string *buf, char **line);
void				ft_buf_update(t_string *buf, char *tmp);
void				ft_termget_buf_setup(t_string *buf);
int32_t				ft_term_line_continuation(char *line);
int32_t				ft_term_line_continuation2(int32_t ret);
uint32_t			ft_termget_complete_line(char **line, t_shenv *shenv);

void				ft_move_left_cursor(t_string *buf);
void				ft_move_right_cursor(t_string *buf);
void				ft_move_up_cursor(t_string *buf);
void				ft_move_down_cursor(t_string *buf);
void				ft_move_start_line(t_string *buf);
void				ft_move_end_line(t_string *buf);
void				ft_move_prev_word(t_string *buf);
void				ft_move_next_word(t_string *buf);

void				ft_screen_clear(void);
void				ft_delete_char(t_string *buf);
int32_t				ft_kill_line(t_string *buf, t_list **paste_history);
int32_t				ft_paste_line(t_string *buf, char *command,
									t_list *paste_history);
void				ft_set_insert(void);
void				ft_unset_insert(void);
int32_t				ft_set_echo_mode(void);
int32_t				ft_set_echok_mode(void);
void				ft_set_am(void);
void				ft_print_history_len(t_list *list);
void				ft_print_history(t_string *buf, char *history);
t_string			*ft_t_string_concat(t_string *string, char *str);
t_string			*ft_t_string_insert(t_string *string, char *str);
t_list				**ft_get_history_list(void);
void				ft_get_history(t_list *history, char *command,
										t_string *buf);
void				ft_explore_paste_history(t_string *buf,
						t_list **static_history, t_list **history_base,
						t_list **current_yanking);
int					ft_exec_special_event(t_shenv *shenv, t_string *buf,
									t_list **paste_history, char *command);
void				ft_erase_line(void);
void				ft_append_line(char **line, char **final, uint32_t type);
/*
** Prompt
*/

void				ft_put_prompt(void);
void				ft_set_and_put_prompt(t_prompt new_prompt);
t_prompt_state		*ft_get_prompt_state_machine(void);
t_prompt			*ft_get_current_prompt(void);
void				ft_set_current_prompt(t_prompt new_prompt);
uint32_t			ft_get_current_prompt_len(void);
char				*ft_get_current_prompt_string(void);

/*
** Line Attributes
*/

t_line_attributes	*ft_get_line_attributes(void);

#endif
