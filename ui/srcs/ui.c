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

#include "ui.h"

//# define lol  "62.210.34.198"
# define loli  "10.13.13.4"
# include <stdio.h>
# include <unistd.h>

int	main(void)
{
	int					socketfd;
	struct sockaddr_in	serv_sock;

	ft_bzero(&serv_sock, sizeof(struct sockaddr));
	serv_sock.sin_family = PF_INET;
	serv_sock.sin_port = htons(7777);
	serv_sock.sin_addr.s_addr = inet_addr(loli);
//	inet_pton( PF_INET, lol, &serv_sock.sin_addr);
//	serv_sock.sin_len =  /* OFFSETOF(struct sockaddr, sa_data) */sizeof(serv_sock.sin_family) + sizeof(lol);
	serv_sock.sin_len = sizeof(serv_sock);
	if (-1 == (socketfd = socket(PF_INET, SOCK_STREAM, 0)))
		perror(UI_NAME " socket()" );
	printf("created as %d\n", socketfd);
	if (-1 == (connect(socketfd, (const struct sockaddr *)&serv_sock, sizeof(serv_sock))))
		perror(UI_NAME " connect()" );
	printf("connected\n");
	write(socketfd, "ping", 4);
	char buffer[255];
	long n;
	while ( (n = read( socketfd, buffer, 200)) ) {
	    write(socketfd, "ping", 5);
	    buffer[n] = 0;
	    printf("%s\n", buffer );
	}

	if ( n < 0 ) {
	    perror( "read" );
	    exit(1);
	}
	return (EXIT_SUCCESS);
}
