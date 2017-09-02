/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 03:24:20 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/24 12:47:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_shell(void)
{
	if (!(g_shell = (t_shell*)ft_memalloc(sizeof(t_shell))))
		ft_error_exit(1, (char*[]){"Shell initialization failed"}, 1);
	g_shell->terminal = STDIN_FILENO;
	g_shell->interactive = isatty(g_shell->terminal);
	if (g_shell->interactive)
	{
		while (tcgetpgrp(g_shell->interactive)
			!= (g_shell->shell_pgid = getpgrp()))
			kill(-g_shell->shell_pgid, SIGSTOP);
		ft_ignore_signals();
		g_shell->shell_pgid = getpid();
		if (-1 == (setpgid(g_shell->shell_pgid, g_shell->shell_pgid)))
			ft_error_exit(1, (char*[]){"Shell initialization failed"}, 1);
		tcsetpgrp(g_shell->terminal, g_shell->shell_pgid);
		tcgetattr(g_shell->terminal, &g_shell->backup_term);
		if (-1 == ft_set_term())
			ft_error_exit(1, (char*[]){"Shell initialization failed"}, 1);
		ft_setup_sighandlers();
	}
}

void	ft_free_t_shell(void)
{
	free(g_shell);
}

void	ft_exit_shell(int exit_status)
{
	ft_unset_term();
	ft_unset_insert();
	ft_putchar('\n');
	exit(POSIX_EXIT_STATUS(exit_status));
}

void	ft_put_shell_in_foreground(void)
{
	tcsetpgrp(g_shell->interactive, g_shell->shell_pgid);
	ft_unset_term();
	ft_set_term();
}
