/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:45:35 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 02:36:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_stop_process(t_supervised_program *prog)
{
	time_t	time;
	time_t	elapsed_time;

	time = time(NULL);
	kill(prog->pid, prog->start_info.stop_signal);
	while ((time = sleep(time)))
		;
	ft_update_process_status(prog->pid);
	while (*ft_get_process_status() != TERMINATED
		&& *ft_get_process_status() != EXITED)
	{
		kill(prog->pid, SIGKILL);
		ft_update_process_status(prog->pid);
	}
}
