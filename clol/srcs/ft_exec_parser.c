/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:14:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 04:25:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_set_terminal_pgid(pid_t gpid)
{
	if (!gpid)
		gpid = getpid();
	setpgid(0, gpid);
	tcsetpgrp(g_shell->terminal, gpid);
}

static void			ft_set_fds(int *stdfd)
{
	dup2(stdfd[0], STDIN_FILENO);
	dup2(stdfd[1], STDOUT_FILENO);
	stdfd[2] == STDIN_FILENO ? 0 : close(stdfd[2]);
	stdfd[3] == STDOUT_FILENO ? 0 : close(stdfd[3]);
}

static t_process	*ft_get_t_process(pid_t pid, pid_t gpid, char **argv)
{
	t_process	*process;

	if (!(process = (t_process*)ft_memalloc(sizeof(t_process))))
		exit(EXIT_FAILURE);
	if (!gpid)
		gpid = pid;
	setpgid(pid, gpid);
	process->pid = pid;
	process->gpid = gpid;
	process->argv = argv;
	return (process);
}

t_process			*ft_start_process(t_parser *simple_cmd, pid_t gpid,
									int *stdfd, t_shenv *shenv)
{
	char		**argv;
	pid_t		pid;
	int			ret;

	if (-1 == (pid = fork()))
		exit(ft_error(1, (char*[]){"fork() failed due to insufficient \
			ressource"}, EXIT_REDIREC_ERROR));
	if (pid)
	{
		while (!waitpid(pid, &ret, WNOHANG | WUNTRACED) && !WIFSTOPPED(ret))
			kill(pid, SIGTSTP);
		argv = ft_get_argv(OR_PARSER_N(simple_cmd, 0));
		return (ft_get_t_process(pid, gpid, argv));
	}
	else
	{
		ft_set_terminal_pgid(gpid);
		ft_reset_signals();
		ft_set_fds(stdfd);
		ft_exec_simple_cmd(simple_cmd, shenv);
		exit(EXIT_FAILURE);
	}
}
