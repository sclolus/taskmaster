/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deamon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:15:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 09:01:34 by sclolus          ###   ########.fr       */
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

# define DEAMON_NAME "deamon"
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

typedef enum	e_socket_status
{
	ERR = 0,
	WORKING,
	CLOSED,
}				t_socket_status;

typedef struct	s_socket
{
	int					fd;
	struct sockaddr_in	client_addr;
	t_socket_status		status;
}				t_socket;

typedef void	(t_socket_action)(t_socket *socket);

int				ft_create_listening_socket(sa_family_t sin_family
										, in_port_t sin_port);
int				ft_accept_connection(t_mem_block *sockets, int serv_sock);
void			ft_map_sockets(t_mem_block *sockets, t_socket_action *f);

/*
** Pong
*/

# define PONG_BUFF_SIZE 5
# define PING "ping"
# define PONG "pong"

void	ft_pong(t_socket *socket);

/*
** Log
*/

void	ft_log(uint32_t n, char **strings);

/*
** Mem_block handling
*/

# define MEM_BLOCK_LIMIT 256
# define DEFAULT_MEM_BLOCK_SIZE (sizeof(t_socket) * 150)

void			*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block		*ft_create_mem_block(uint64_t capacity);

/*
** Error Handling
*/
# define MALLOC_FAILURE "Malloc() failed due to insufficient ressources"
# define TM_ERR(x) DEAMON_NAME ": " x


#endif
