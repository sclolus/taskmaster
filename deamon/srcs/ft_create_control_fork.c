/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_control_fork.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:45:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 01:18:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

t_control_info	ft_create_control_fork(t_connection *connection
						, t_supervised_program *prog, uint32_t proc_nbr)
{
	int		fds[4];
	pid_t	pid;

	if (-1 == pipe((int*)fds) || -1 == (pipe((int*)(fds + 2))))
	{
		ft_sock_send(ERR_CONTROL_FORK, connection->fd);
		ft_log(2, (const char*[]){"Failed to pipe() full duplex ipc: ", prog->name});
		return ((t_control_info){NULL, 0, {0, 0}, -1});
	}
	if (-1 == (pid = fork()))
	{
		ft_sock_send(ERR_CONTROL_FORK, connection->fd);
		ft_log(2, (const char*[]){"ft_create_control_fork() failed: ", prog->name});
		return ((t_control_info){NULL, 0, {0, 0}, -1});
	}
	else if (pid)
	{
		close(fds[1]);
		close(fds[2]);
		return ((t_control_info){prog, proc_nbr, {fds[0], fds[3]}, pid});
	}
	else
	{
		close(fds[0]);
		close(fds[3]);
		ft_control_process(connection, prog, (int[2]){fds[2], fds[1]});
	}
}
