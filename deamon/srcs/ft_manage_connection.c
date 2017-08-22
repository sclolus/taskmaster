/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:00:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 19:31:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

__attribute__((noreturn)) void	ft_manage_connection(t_connection connection)
{
	static char	buf[1024];
	int64_t		len;
	t_list		*progs;

	if (!(progs = ft_parse_conf_file(ft_get_file_content("configure.txt"))))
		exit(EXIT_FAILURE); //
	ft_dump_t_supervised_program(progs);
	while (0 < (len = read(connection.fd, buf, 1023)))
	{
		buf[len] = '\0';
		printf("pid: %d, %s\n", getpid(), buf);
		ft_task_execution(buf, &connection);
	}
	close(connection.fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())});
	exit(EXIT_FAILURE);
}
