/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:11:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 04:01:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

# define AALVES_IP "10.13.13.51441"
# include <stdio.h>
int	main(void)
{
	int					socketfd;
	struct sockaddr_in	serv_sock;

	ft_bzero(&serv_sock, sizeof(struct sockaddr));
	serv_sock.sin_family = PF_INET;
	serv_sock.sin_port = 7777;
	ft_strcpy((char*)&serv_sock.sin_addr.s_addr, AALVES_IP);
	serv_sock.sin_len = /* OFFSETOF(struct sockaddr, sa_data) */sizeof(serv_sock.sin_family) + sizeof(AALVES_IP);
	if (-1 == (socketfd = socket(PF_INET, SOCK_STREAM, 0)))
		perror(DEAMON_NAME " socket()" );
	if (-1 == (bind(socketfd, (const struct sockaddr*)&serv_sock
					, sizeof(struct sockaddr))))
		perror(DEAMON_NAME " bind()" );
	if (-1 == (listen(socketfd, MAX_PENDING_CONNECTION)))
		perror(DEAMON_NAME " listen()" );
	if (-1 == accept(socketfd, &serv_sock, &(socklen_t){OFFSETOF(struct sin_addr, sin_addr.s_addr) + sizeof(AALVES_IP)}))
		perror(DEAMON_NAME " accept()" );
	ft_putendl_fd("Lol, this is a test", socketfd);
	return (EXIT_SUCCESS);
}
