/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deamon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:15:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 02:37:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOCKET_H
# define FT_SOCKET_H

# include <unistd.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <stdio.h>
#include <sys/select.h>
# include "libft.h"


# define SERVER_IP "10.13.7.13"

# define READ_SET 0
# define WRITE_SET 1
# define ERROR_SET 2

typedef struct	s_connection
{
	int			fd;
	struct sockaddr_in	addr;
}				t_connection;

typedef struct	s_sock_set
{
    int		nfds;
    fd_set	readfds;
    fd_set	writefds;
    fd_set	errorfds;
}				t_sock_set;



int			ft_create_socket(const int domain, const int type, const int protocol);
int32_t		ft_wait_connection(const t_connection connection, const uint32_t max);
ssize_t		ft_write_socket(const char *str, const int fd);


t_sock_set	*ft_get_sock_set();
void		ft_watch_socket(int socketfd, int type);
void		ft_unwatch_socket(int socketfd, int type);
int			ft_socket_to_read();
int32_t		ft_sock_log(uint32_t n, const char **str
					, int32_t return_status, t_connection connection);

#endif
