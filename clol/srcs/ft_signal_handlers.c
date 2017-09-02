/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:17:24 by aalves            #+#    #+#             */
/*   Updated: 2017/05/09 14:31:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void		ft_handler_int(int signum)
{
	if (signum == SIGINT)
		;
	else
		ft_putstr_fd("signal handling error", 2);
}

void		ft_handler_tstp(int signum)
{
	if (signum == SIGTSTP)
		;
}

void		ft_handler_cont(int signum)
{
	if (signum == SIGCONT)
	{
		g_shell->shell_pgid = getpgrp();
		g_shell->interactive = isatty(g_shell->terminal);
		while (tcgetpgrp(g_shell->interactive)
				!= (g_shell->shell_pgid))
			kill(-g_shell->shell_pgid, SIGSTOP);
	}
	else
		ft_putstr_fd("signal handling error", 2);
}
