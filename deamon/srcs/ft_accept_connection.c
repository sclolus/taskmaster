/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:21:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 09:00:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

int	ft_accept_connection(t_mem_block *sockets, int serv_sock)
{
	struct sockaddr_in	client_sock;
	int					connection_fd;
	uint32_t			len;
	int					flags;

	len = sizeof(client_sock);
	if (-1 == (connection_fd = accept(serv_sock
				, (struct sockaddr*)&client_sock, &len)))
	{
		perror(TM_ERR("accept()"));
		exit(EXIT_FAILURE);
	}
	ft_log(2, (char*[]){"New connection made: ", ft_itoa(connection_fd)});
	flags = fcntl(connection_fd, F_GETFL, 0);
	fcntl(connection_fd, F_SETFL, flags | O_NONBLOCK);
	ft_mem_block_push_back_elem(sockets, &(t_socket){connection_fd
				, client_sock, WORKING}, sizeof(t_socket));
	return (connection_fd);
}
