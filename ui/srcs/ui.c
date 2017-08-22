/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:11:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 21:22:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
//#include "termcaps.h"

//# define loli  "62.210.34.198"
# define loli  "10.13.1.11"
# include <stdio.h>
# include <unistd.h>

int	main(void)
{
    int					socketfd;
    struct sockaddr_in	serv_sock;

    ft_bzero(&serv_sock, sizeof(struct sockaddr));
    serv_sock.sin_family = PF_INET;
    serv_sock.sin_port = htons(7777);
    inet_pton( PF_INET, loli, &serv_sock.sin_addr);
    serv_sock.sin_len = sizeof(serv_sock);
    if (-1 == (socketfd = socket(PF_INET, SOCK_STREAM, 0)))
		perror(UI_NAME " socket()" );
    printf("created as %d\n", socketfd);

    if (-1 == (connect(socketfd, (const struct sockaddr *)&serv_sock, sizeof(serv_sock))))
	perror(UI_NAME " connect()" );

    printf("connected\n");

    char line[2000];
	int64_t	n;
    while (1)
    {
		printf("?> ");
		fflush(NULL);
		scanf("%s", line);
		printf("send, %s\n", line);
		if (-1 == write(socketfd, line, ft_strlen(line)))
			ft_error_exit(1, (char*[]){"connection unexpectly ended"}, EXIT_FAILURE);
		n = read(socketfd, line, 127);
		line[n] = '\0';
		printf("Deamon responded: %s\n", line);
    }
    return (EXIT_SUCCESS);
}
