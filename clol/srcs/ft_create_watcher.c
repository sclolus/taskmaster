/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 09:44:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 09:49:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_socket.h"

pid_t	ft_create_watcher(t_connection connection)
{
	pid_t	pid;

	if (-1 == (pid = fork()))
		return (ft_error(1, (char*[]){ERR_FORK_WATCHER}, -1));
	else if (pid)
		return (pid);
	else
		ft_watcher(connection);
}
