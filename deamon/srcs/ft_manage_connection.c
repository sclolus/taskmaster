/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:00:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 11:01:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

__attribute__((noreturn)) void	ft_manage_connection(t_connection connection)
{
	static char	buf[1024];
	int64_t		len;

	while (0 < (len = read(connection.fd, buf, 1023)))
	{
		buf[len] = '\0';
		printf("pid: %d, %s\n", getpid(), buf);
	}
	close(connection.fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())});
	exit(EXIT_FAILURE);
}
