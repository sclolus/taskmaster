/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:15:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 02:44:49 by sclolus          ###   ########.fr       */
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
		if (TASK_RESTART == buf[i])
			ft_restart_process(prog);
		else if (TASK_STOP == buf[i])
			ft_stop_process(prog);
		else if (TASK_STATUS == buf[i])
			ft_send_status(prog, fds);
		else if (TASK_RELOAD == buf[i])
			ft_reload_routine(prog, fds);
		i++;
	}
	read_on_socket = 0;
	(void)connection;
}

__attribute__((noreturn)) void ft_control_process(t_connection *connection
							, t_supervised_program *prog, int fds[2])
{
	ft_set_control_fork_signals();
	ft_set_process_status(WORKING);
	prog->pid = ft_launch_process(prog);
	while (42)
	{
		ft_update_process_status(prog->pid);
		if (read_on_socket)
			ft_control_process_tasks(connection, prog, fds);
	}
}
