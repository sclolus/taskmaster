/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_deamon_signals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:23:36 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 10:53:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

static void	ft_handler_sigchild(int signum)
{
	int		status;
	pid_t	pid;

	if (signum == SIGCHLD)
	{
		pid = wait(&status);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			ft_mark_instance(pid, TERMINATED);
		else if (WIFSTOPPED(status))
			ft_mark_instance(pid, SUSPENDED);
		else
			ft_mark_instance(pid, WORKING);
	}
}

int			ft_set_deamon_signals(void)
{
	if (SIG_ERR == signal(SIGCHLD, &ft_handler_sigchild))
		ft_error_exit(1, (char*[]){ERR_SET_SIG_DEAMON}, EXIT_FAILURE);
	return (1);
}
