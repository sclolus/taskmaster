/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:11:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 08:59:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

//# define AALVES_IP "10.13.13.2"
# include <stdio.h>

int	main(void)
{
	t_mem_block			*sockets;
	int					socketfd;

	sockets = ft_create_mem_block(DEFAULT_MEM_BLOCK_SIZE);
	socketfd = ft_create_listening_socket(PF_INET, 7777);
	while (42)
	{
		ft_accept_connection(sockets, socketfd);
		ft_map_sockets(sockets, &ft_pong);
	}
	return (EXIT_SUCCESS);
}
