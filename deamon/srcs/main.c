/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:11:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 20:17:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

# include <stdio.h>

int	main(void)
{
	t_mem_block			*instances;
	int					socketfd;

	ft_start_deamon();
	instances = ft_get_instances();
	socketfd = ft_create_listening_socket(PF_INET, 7777);
	while (42)
		ft_accept_connection(instances, socketfd);
	return (EXIT_SUCCESS);
}
