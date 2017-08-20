/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deamon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:15:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 11:00:36 by sclolus          ###   ########.fr       */
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
** Socket handling
*/

typedef enum	e_instance_status
{
	ERR = 0,
	WORKING,
	TERMINATED,
	SUSPENDED,
}				t_instance_status;

typedef struct	s_connection
{
	int					fd;
	struct sockaddr_in	client_addr;
}				t_connection;

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
/*
** Error Handling
*/

# define ERR_FORK_INSTANCE "ft_fork_instance() failed"
# define MALLOC_FAILURE "Malloc() failed due to insufficient ressources"
# define TM_ERR(x) DEAMON_NAME ": " x


#endif
