/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_instance_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 20:21:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 01:25:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

__attribute__((noreturn)) void	ft_task_instance_exit(char *instruction, t_list *progs
							, t_list **control_infos)
{
	ft_task_stop_all(instruction, progs, control_infos);
	ft_sock_send(INSTANCE_UI_EXIT_MESSAGE, g_connection->fd);
	close(g_connection->fd);
	ft_log(2, (const char*[]){"Connection ended: ", ft_itoa(getpid())}); //
	exit(EXIT_SUCCESS);
}
