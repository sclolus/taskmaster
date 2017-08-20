/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:11:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 05:25:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

# define AALVES_IP "10.13.13.2"
# include <stdio.h>

int	main(void)
{
	int					socketfd;
	struct sockaddr_in	serv_sock;

	ft_bzero(&serv_sock, sizeof(struct sockaddr));
	serv_sock.sin_family = PF_INET;
	serv_sock.sin_port = ANYPORT;
	serv_sock.sin_addr.s_addr = /* inet_addr(AALVES_IP) */INADDR_ANY;
	serv_sock.sin_len = sizeof(serv_sock.sin_family) + sizeof(AALVES_IP);
	if (-1 == (socketfd = socket(PF_INET, SOCK_STREAM, 0)))
		perror(TM_ERR("socket()"));
	if (-1 == (bind(socketfd, (const struct sockaddr*)&serv_sock
					, sizeof(struct sockaddr))))
		perror(TM_ERR("bind()"));
	if (-1 == (listen(socketfd, MAX_PENDING_CONNECTION)))
		perror(TM_ERR("listen()"));
	if (-1 == accept(socketfd, (struct sockaddr*)&serv_sock, &(socklen_t){OFFSETOF(struct sockaddr_in, sin_addr) + sizeof(AALVES_IP)}))
		perror(TM_ERR("accept()"));
	static char buf[12];
	while (42)
	{
		ft_putendl_fd("Lol, this is a test", socketfd);
		ft_putnbr((int)read(socketfd, buf, 12));
	}
	return (EXIT_SUCCESS);
}
