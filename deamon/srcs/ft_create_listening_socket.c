/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_listening_socket.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:09:17 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 08:46:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

int	ft_create_listening_socket(sa_family_t sin_family, in_port_t sin_port)
{
	int					socketfd;
	struct sockaddr_in	serv_sock;

	serv_sock.sin_family = sin_family;
	serv_sock.sin_port = htons(sin_port);
	serv_sock.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_sock.sin_len = sizeof(struct sockaddr_in);
	if (-1 == (socketfd = socket(PF_INET, SOCK_STREAM, 0)))
	{
		perror(TM_ERR("socket()"));
		exit(EXIT_FAILURE);
	}
	int yes = 1;
	if (setsockopt(socketfd, SOL_SOCKET,SO_REUSEADDR,&yes,sizeof (yes)) == -1)
		perror(TM_ERR("setsockopt"));
	if (-1 == (bind(socketfd, (const struct sockaddr*)&serv_sock
					, sizeof(struct sockaddr))))
	{
		perror(TM_ERR("bind()"));
		exit(EXIT_FAILURE);
	}
	if (-1 == (listen(socketfd, MAX_PENDING_CONNECTION)))
	{
		perror(TM_ERR("listen()"));
		exit(EXIT_FAILURE);
	}
	return (socketfd);
}
