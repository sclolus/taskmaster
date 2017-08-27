/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:45:35 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:04:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_stop_process(t_supervised_program *prog)
{
	unsigned int	start_time;

	start_time = (unsigned int)prog->start_info.stop_time;
	kill(prog->pid, prog->start_info.stop_signal);
	while ((start_time = sleep(start_time)))
		;
	ft_update_process_status(prog->pid);
	while (*ft_get_process_status() != TERMINATED
		&& *ft_get_process_status() != EXITED)
	{
		kill(prog->pid, SIGKILL);
		ft_update_process_status(prog->pid);
	}
	exit(EXIT_SUCCESS);
}
