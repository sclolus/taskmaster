/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deamon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:15:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 22:16:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEAMON_H
# define DEAMON_H

# include "taskmaster.h"
# include "libft.h"
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>

# define DEAMON_NAME "deamon"
# undef ERROR_NAME_HEADER
# define ERROR_NAME_HEADER DEAMON_NAME
# define MAX_PENDING_CONNECTION 128

# define OFFSETOF(type, member) ((uint64_t)(&((type*)0)->member))

/*
** DEBUG
*/ //

# define CHECK(x) do {ft_putendl_fd("_____", 2);ft_putendl_fd(#x, 2);ft_putendl_fd("_____", 2);} while (0);

typedef struct	s_mem_block
{
	uint64_t			capacity;
	uint64_t			offset;
	void				*block;
	struct s_mem_block	*next;
}				t_mem_block;

/*
** Deamon initialization
*/

void			ft_start_deamon(void);

/*
** Socket handling
*/

typedef enum	e_instance_status
{
	ERR = 0,
	WORKING,
	EXITED,
	TERMINATED,
	SUSPENDED,
}				t_instance_status;

typedef t_instance_status t_process_status;

typedef struct	s_instance
{
	t_connection		connection;
	pid_t				pid;
	t_instance_status	status;
}				t_instance;

//typedef void	(t_socket_action)(t_socket *socket);

int				ft_create_listening_socket(sa_family_t sin_family
										, in_port_t sin_port);
int				ft_accept_connection(t_mem_block *sockets, int serv_sock);
pid_t			ft_fork_instance(t_connection connection);
void			ft_manage_connection(t_connection connection)
					__attribute__((noreturn));
void			ft_mark_instance(pid_t pid, t_instance_status status);
const char		*ft_get_status_str(t_instance_status status);
t_mem_block		*ft_get_instances(void);
//void			ft_map_sockets(t_mem_block *sockets, t_socket_action *f);

/*
** Configuration File Parsing
*/

# define PARSE_CONF_FILE_ERR "Could not parse configuration file"

typedef int32_t (t_parsing_case)(char *, uint32_t, t_supervised_program *);
typedef int32_t (t_parsing_action)(char *, uint32_t, t_supervised_program *);
typedef struct	s_conf_parsing_state
{
	char				*id;
	t_parsing_case		*f_case;
	t_parsing_action	*f_action;
}				t_conf_parsing_state;

t_list		*ft_parse_conf_file(char *buffer);
int32_t		ft_is_prog_name_case(char *line, uint32_t index
							, t_supervised_program *prog);
uint32_t	ft_skip_cmd_header(char *line, uint32_t index);
uint32_t	ft_skip_one_line(char *line, uint32_t index);
uint32_t	ft_skip_one_prog(char *buffer, uint32_t i);
char		*ft_get_parsing_path(char *line, uint32_t index);
t_list		*ft_parse_one_prog(char *line, uint32_t index);
int32_t		ft_parse_one_line(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_stderr_redirec(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_stdout_redirec(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_stop_time(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_stop_signal(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_start_time(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_start_retries(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_autorestart(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_autostart(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_working_dir(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_cmd(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_prog_name(char *line, uint32_t index
						, t_supervised_program *prog);
int32_t		ft_get_nbr_procs(char *line, uint32_t index
						, t_supervised_program *prog);


/*
** Instructions
*/

# define INSTANCE_UI_EXIT_MESSAGE "Connection successfully ended"
# define DEAMON_UI_KILL_MESSAGE "Deamon succesfully terminated"

typedef void (t_f_instruction)(char *, t_list *, t_list **);

typedef struct	s_instruction
{
	char			*id;
	t_f_instruction	*f;
}				t_instruction;

void			ft_task_execution(char *instruction, t_list *progs);
int32_t			ft_parse_task(char *task, t_list *progs
					, t_supervised_program **prog, uint32_t *proc_num);
void			ft_task_start_process(char *instruction, t_list *progs
					, t_list **control_infos);
void			ft_task_stop_process(char *instruction, t_list *progs
					, t_list **control_infos);
void			ft_task_stop_all(char *instruction, t_list *progs
					, t_list **control_infos);
void			ft_task_restart_process(char *instruction, t_list *progs
					, t_list **control_infos);
void			ft_task_instance_exit(char *instruction, t_list *progs
					, t_list **control_infos) __attribute__((noreturn));

//void	ft_kill_deamon() __attribute__((noreturn));
//void	ft_instance_exit() __attribute__((noreturn));


/*
** Controlling processes
*/

# define TASK_RESTART 0
# define TASK_STOP 1
# define TASK_STATUS 2
# define TASK_RELOAD 3

extern t_connection	*g_connection;

typedef struct	s_control_info
{
	t_supervised_program	*prog;
	uint32_t				proc_nbr;
	int						fd[2];
	pid_t					pid;
}				t_control_info;

extern int8_t	read_on_socket;

t_control_info		ft_create_control_fork(t_connection *connection
									, t_supervised_program *prog, uint32_t proc_nbr);
void				ft_control_process(t_connection *connection
	, t_supervised_program *prog, int fds[2]) __attribute__((noreturn));
void				ft_set_process_status(t_process_status init_status);
t_process_status	*ft_get_process_status(void);
void				ft_update_process_status(pid_t pid);
void				ft_set_control_fork_signals(void);

pid_t				ft_launch_process(t_supervised_program *prog);
void				ft_restart_process(t_supervised_program *prog) __attribute__((noreturn));
void				ft_stop_process(t_supervised_program *prog) __attribute__((noreturn));
void				ft_send_status(t_supervised_program *prog, int fds[2]);

# define RELOAD_FORK_SUCCESS 1

void				ft_reload_routine(t_supervised_program *prog, int fds[2]) __attribute__((noreturn));

/*
** Pong
*/

# define PONG_BUFF_SIZE 5
# define PING "ping"
# define PONG "pong"

//void	ft_pong(t_socket *socket);

/*
** Log
*/

void	ft_log(uint32_t n, const char * const *strings);
ssize_t	ft_sock_send(char *str, int fd);

/*
** Mem_block handling
*/

# define MEM_BLOCK_LIMIT 256
# define DEFAULT_MEM_BLOCK_SIZE (sizeof(t_instance) * 150)

void			*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block		*ft_create_mem_block(uint64_t capacity);

/*
** Signals
*/

# define ERR_SET_SIG_DEAMON "signal() failed to set deamon signal handlers"

int			ft_set_deamon_signals(void);
void		ft_reset_signals(void);
void		ft_ignore_signals(void);

/*
** Error Handling
*/

# define ERR_LAUNCH_PROCESS "Failed to launch process"
# define ERR_FORK_INSTANCE "ft_fork_instance() failed"
# define ERR_CONTROL_FORK "Failed to fork() control process"
# define MALLOC_FAILURE "Malloc() failed due to insufficient ressources"
# define TM_ERR(x) DEAMON_NAME ": " x


#endif
