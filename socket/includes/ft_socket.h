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

typedef struct	s_connection
{
	int			fd;
	struct sockaddr_in	addr;
}				t_connection;


int	ft_create_socket(const int domain, const int type, const int protocol);
int32_t	ft_wait_connection(const t_connection connection, const uint32_t max);

#endif
