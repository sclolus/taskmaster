/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instance_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:39:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 19:58:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

__attribute__((noreturn)) void	ft_instance_exit(t_connection *connection)
{
	ft_sock_send(INSTANCE_UI_EXIT_MESSAGE, connection->fd);
	close(connection->fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())});
	exit(EXIT_SUCCESS);
}
