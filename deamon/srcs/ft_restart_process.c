/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restart_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 02:20:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 02:35:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_restart_process(t_supervised_program *prog)
{
	while (*ft_get_process_status() != TERMINATED
		&& *ft_get_process_status() != EXITED)
	{
		kill(prog->pid, SIGKILL);
		ft_update_process_status(prog->pid);
	}
	ft_launch_process(prog);
}
