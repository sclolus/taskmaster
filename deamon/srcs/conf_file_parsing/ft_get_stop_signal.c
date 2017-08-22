/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stop_signal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:42:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:14:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_stop_signal(char *line, uint32_t index
						, t_supervised_program *prog)
{
	static char	*signals[] = {"SIGHUP", "SIGINT", "SIGQUIT", "SIGILL"
		, "SIGTRAP", "SIGABRT", "SIGEMT", "SIGFPE", "SIGKILL", "SIGBUS"
		, "SIGSEGV", "SIGSYS", "SIGPIPE", "SIGALRM", "SIGTERM", "SIGURG"
		, "SIGSTOP", "SIGTSTP", "SIGCONT", "SIGCHLD", "SIGTTIN", "SIGTTOU"
		, "SIGIO", "SIGXCPU", "SIGXFSZ", "SIGVTALRM", "SIGPROF", "SIGWINCH"
		, "SIGINFO", "SIGUSR1", "SIGUSR2"};
	uint32_t	i;

	i = 0;
	index = ft_skip_cmd_header(line, index);
	while (i < sizeof(signals) / sizeof(char *))
	{
		if (ft_strnequ(line + index, signals[i], ft_strlen(signals[i])))
		{
			prog->start_info.stop_signal = (int)i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}
