/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:15:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/24 01:58:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

int8_t	read_on_socket = 0;

static inline void	ft_control_process_tasks(t_connection *connection
							, t_supervised_program *prog, int fds[2])
{
	// make DFA please
	static char	buf[128];
	ssize_t		n;
	uint32_t	i;

	i = 0;
	n = read(fds[0], buf, 128);
	while (i < n)
	{
/* 		if (TASK_RESTART == buf[i]) */
/* 			/ft_restart_process(prog); */
/* 		else if (TASK_STOP == buf[i]) */
/* 			ft_stop_process(prog); */
/* 		else if (TASK_KILL == buf[i]) */
/* 			ft_kill_process(prog); */
		printf("fork: read: %hhu\n", *buf);
		write(fds[1], buf + i, 1);
		i++;
	}
	read_on_socket = 0;
	(void)connection;
	(void)prog;
}

__attribute__((noreturn)) void ft_control_process(t_connection *connection
							, t_supervised_program *prog, int fds[2])
{
	pid_t	pid = 0; //

	(void)pid;
	ft_set_control_fork_signals();
	ft_set_process_status(WORKING);
	while (42)
	{
//		ft_update_process_status(pid);
		if (read_on_socket)
		{

			ft_control_process_tasks(connection, prog, fds);
		}
	}
}
