/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:11:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 06:57:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

//# define AALVES_IP "10.13.13.2"
# include <stdio.h>

int	main(void)
{
	int					socketfd;
	struct sockaddr_in	serv_sock;
	struct sockaddr_in	client_sock;
	uint32_t	len = sizeof(client_sock);

	ft_bzero(&serv_sock, sizeof(struct sockaddr_in));
	serv_sock.sin_family = PF_INET;
	serv_sock.sin_port = htons(/* ANYPORT */7777);
	serv_sock.sin_addr.s_addr = /* inet_addr(AALVES_IP) */htonl(INADDR_ANY);
	serv_sock.sin_len = sizeof(struct sockaddr_in);
	if (-1 == (socketfd = socket(PF_INET, SOCK_STREAM, 0)))
	{
		perror(TM_ERR("socket()"));
		exit(EXIT_FAILURE);
	}
	printf("socket created\n");
	if (-1 == (bind(socketfd, (const struct sockaddr*)&serv_sock
					, sizeof(struct sockaddr_in))))
	{
		perror(TM_ERR("bind()"));
		exit(EXIT_FAILURE);
	}
	printf("socket binded\n");
	if (-1 == (listen(socketfd, MAX_PENDING_CONNECTION)))
	{
		perror(TM_ERR("listen()"));
		exit(EXIT_FAILURE);
	}
	printf("port: %hu\n", serv_sock.sin_port);
//	getsockname(socketfd, (struct sockaddr*)&serv_sock, &len);
	printf("listen() success\n");
	int		connection_fd;
	if (-1 == (connection_fd = accept(socketfd, (struct sockaddr*)&client_sock, &len)))
	{
		perror(TM_ERR("accept()"));
		exit(EXIT_FAILURE);
	}
	printf("accept() connected");
	static char buf[12];
	int64_t	n;
	while (42)
	{
		n = read(connection_fd, buf, 11);
		buf[n] = '\0';
		if (ft_strequ(buf, "ping"))
			ft_putendl_fd("pong", connection_fd);
	}
	return (EXIT_SUCCESS);
}
