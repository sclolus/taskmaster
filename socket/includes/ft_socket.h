/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deamon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:15:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 04:27:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOCKET_H
# define FT_SOCKET_H

# include <unistd.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <stdio.h>
# include "libft.h"


# define SERVER_IP "10.13.7.13"



typedef struct	s_connection
{
	int			fd;
	struct sockaddr_in	addr;
}				t_connection;


int	ft_create_socket(const int domain, const int type, const int protocol);
int32_t	ft_wait_connection(const t_connection connection, const uint32_t max);
ssize_t	ft_write_socket(const char *str, const int fd);

#endif
