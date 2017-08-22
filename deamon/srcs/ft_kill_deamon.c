/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_deamon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:46:41 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 14:56:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_kill_deamon(t_connection *connection)
{
	ft_sock_send(DEAMON_UI_KILL_MESSAGE, connection->fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())});
	ft_log(1, (const char*[]){"Killed deamon"});
	kill(0, SIGKILL);
	exit(EXIT_SUCCESS);
}
