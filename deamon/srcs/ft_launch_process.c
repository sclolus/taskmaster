/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 23:27:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 19:29:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline pid_t	ft_launch_process(t_supervised_program *prog)
{
	pid_t	pid;

	if (-1 == (pid = fork()))
		ft_error_exit(1, (char*[]){"Failed to launch process"}, EXIT_FAILURE);
	else if (pid)
		return (pid);
	else
	{
//		ft_set_fds()
		if (-1 == execve(prog->start_info.cmd[0], prog->start_info.cmd, prog->env))
			perror(DEAMON_NAME);
		exit(EXIT_FAILURE);
	}
}
