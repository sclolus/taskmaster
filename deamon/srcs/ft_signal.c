/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:30:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/24 01:44:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void		ft_reset_signals(void)
{
	int	i;

	i = 1;
	while (i < 32)
	{
		if (i == SIGKILL || i == SIGSTOP)
			i++;
		if (signal(i++, SIG_DFL) == SIG_ERR)
			ft_error_exit(1, (char*[]){"Signal reset error"}, -1);
	}
}

void		ft_ignore_signals(void)
{
	int	i;

	i = 1;
	while (i < 32)
	{
		if (i == SIGKILL || i == SIGSTOP)
			i++;
		if (signal(i++, SIG_IGN) == SIG_ERR)
			ft_error_exit(1, (char*[]){"Signal ignore error"}, -1);
	}
}
