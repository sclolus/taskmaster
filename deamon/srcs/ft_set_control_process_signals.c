/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_control_process_signals.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:29:14 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/24 01:57:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

static void	ft_control_fork_handler_usr1(int signum)
{
	if (signum)
		read_on_socket = 1;
}

void	ft_set_control_fork_signals(void)
{
	ft_reset_signals();
	if (SIG_ERR == signal(SIGUSR1, &ft_control_fork_handler_usr1))
		ft_error_exit(1, (char*[]){"Failed to set control_fork signals"}
			, EXIT_FAILURE);
}
