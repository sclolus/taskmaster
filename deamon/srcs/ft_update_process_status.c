/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_process_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 02:10:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 19:32:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_update_process_status(pid_t pid)
{
	int	status;

	waitpid(pid, &status, WNOHANG | WUNTRACED);
	if (WIFEXITED(status))
		ft_set_process_status(EXITED);
	else if (WIFSIGNALED(status))
		ft_set_process_status(TERMINATED);
	else if (WIFSTOPPED(status))
		ft_set_process_status(SUSPENDED);
	else
		ft_set_process_status(WORKING);
}
