/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_sockets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:27:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 08:57:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_map_sockets(t_mem_block *sockets, t_socket_action *f)
{
	uint64_t	i;

	i = 0;
	while (i * sizeof(t_socket) < sockets->offset)
	{
		ft_log(2, (char*[]){"Mapping on socket: ", ft_itoa(((t_socket*)sockets->block + i)->fd)});
		f(((t_socket*)sockets->block + i));
		i++;
		if (i * sizeof(t_socket) >= sockets->offset && sockets->next)
		{
			sockets = sockets->next;
			i = 0;
		}
	}
}
