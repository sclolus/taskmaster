/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:21:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 10:58:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline static int	ft_create_new_instance(t_mem_block *instances
						, int connection_fd, struct sockaddr_in *client_sock)
{
	pid_t	pid;

	if (-1 == (pid = ft_fork_instance((t_connection){connection_fd
					, *client_sock})))
	{
		ft_sock_send(ERR_FORK_INSTANCE, connection_fd);
		close(connection_fd);
		return (0);
	}
	close(connection_fd);
	ft_mem_block_push_back_elem(instances, &(t_instance){{connection_fd
					, *client_sock}, pid, WORKING}, sizeof(t_instance));
	ft_log(2, (const char*[]){"New instance created: ", ft_itoa(pid)});
	return (1);
}

int		ft_accept_connection(t_mem_block *instances, int serv_sock)
{
	struct sockaddr_in	client_sock;
	int					connection_fd;
	uint32_t			len;

	len = sizeof(client_sock);
	if (-1 == (connection_fd = accept(serv_sock
				, (struct sockaddr*)&client_sock, &len)))
	{
		perror(TM_ERR("accept()"));
		exit(EXIT_FAILURE);
	}
	ft_log(2, (const char*[]){"New connection made: ", ft_itoa(connection_fd)});
	return (ft_create_new_instance(instances, connection_fd, &client_sock));
}
/* 	flags = fcntl(connection_fd, F_GETFL, 0); */
/* 	fcntl(connection_fd, F_SETFL, flags | O_NONBLOCK); */
