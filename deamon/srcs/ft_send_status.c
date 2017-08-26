/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 02:36:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 02:40:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_send_status(t_supervised_program *prog, int fds[2])
{
	t_process_status	status;
	ft_update_process_status(prog->pid);
	status = *ft_get_process_status();
	if (ft_is_little_endian())
		write(fds[1], &status, 1);
	else
		write(fds[1], (char*)&status + (sizeof(t_process_status) - 1), 1);
}
