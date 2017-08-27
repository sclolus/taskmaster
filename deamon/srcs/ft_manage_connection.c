/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:00:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:33:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

t_connection	*g_connection;

__attribute__((noreturn)) void	ft_manage_connection(t_connection connection)
{
	static char	buf[1024];
	int64_t		len;
	t_list		*progs;

	(void)connection;
	if (!(progs = ft_parse_conf_file(ft_get_file_content("configure.txt"))))
		exit(EXIT_FAILURE); //
	ft_dump_t_supervised_program(progs);
	g_connection = &connection;
	while (0 < (len = read(connection.fd, buf, 1023)))
	{
		buf[len] = '\0';
		ft_task_execution(buf, progs);
	}
	close(connection.fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())});
	exit(EXIT_FAILURE);
}
