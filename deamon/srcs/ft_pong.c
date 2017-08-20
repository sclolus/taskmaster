/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pong.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:31:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 09:01:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_pong(t_socket *socket)
{
	static char buf[PONG_BUFF_SIZE];
	int64_t		len;

	if (-1 == (len = read(socket->fd, buf, PONG_BUFF_SIZE - 1)))
	{
		if (errno != EAGAIN)
		{
			close(socket->fd);
			socket->status = CLOSED;
		}
	}
	else
	{
		if (ft_strequ(buf, PING))
		{
			ft_log(1, (char*[]){"Received ping"});
			ft_putendl_fd(PONG, socket->fd);
			ft_log(1, (char*[]){"Send back pong\n"});
		}
	}
}
