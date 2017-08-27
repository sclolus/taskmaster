/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 23:27:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:53:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline pid_t	ft_launch_process(t_supervised_program *prog)
{
	pid_t	pid;

	if (-1 == (pid = fork()))
		ft_error_exit(1, (char*[]){"Failed to launch process"}, EXIT_FAILURE);
	else if (pid)
	{
		ft_sock_send("Started ", g_connection->fd);
		ft_sock_send(prog->name, g_connection->fd);
		return (pid);
	}
	else
	{
//		ft_set_fds()
//		umask(prog->start_info.umask);
		if (-1 == execve(prog->start_info.cmd[0], prog->start_info.cmd, prog->env))
			perror(DEAMON_NAME);
		ft_sock_send("Failed to launch", g_connection->fd);
		ft_sock_send(prog->start_info.cmd[0], g_connection->fd);
		exit(EXIT_FAILURE);
	}
}
