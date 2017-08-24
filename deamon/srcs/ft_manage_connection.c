/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:00:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/24 01:58:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

__attribute__((noreturn)) void	ft_manage_connection(t_connection connection)
{
	static char	buf[1024];
	int64_t		len;
	t_list		*progs;
	t_control_info info;

	if (!(progs = ft_parse_conf_file(ft_get_file_content("configure.txt"))))
		exit(EXIT_FAILURE); //
	ft_dump_t_supervised_program(progs);
	info = ft_create_control_fork(&connection, progs->content);
	while (0 < (len = read(connection.fd, buf, 1023)))
	{
		buf[len] = '\0';
		printf("pid: %d, %s\n", getpid(), buf);
//		ft_task_execution(buf, &connection);
		write(connection.fd, "ye", 2);
		write(info.fd[1], buf, 1);
		kill(info.pid, SIGUSR1);
		char	test;
		read(info.fd[0], &test, 1);
		printf("read: %hhu\n", test);
	}
	close(connection.fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())});
	exit(EXIT_FAILURE);
}
