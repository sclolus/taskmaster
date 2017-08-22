/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:32:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 15:02:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_task_execution(char *instruction, t_connection *connection)
{
	static t_instruction instructions[] =
	{
		{"exit", &ft_instance_exit},
		{"start", &ft_start_process},
		{"stop", &ft_stop_process},
		{"kill_deamon", &ft_kill_deamon}
	};
	uint32_t	i;

	i = 0;
	while (i < sizeof(instructions) / sizeof(t_instruction))
	{
		if (ft_strnequ(instruction, instructions[i].id, ft_strlen(instructions[i].id)))
		{
			instructions[i].f(connection);
			return ;
		}
		i++;
	}
	ft_sock_send("Command not found: ", connection->fd);
	ft_sock_send(instruction, connection->fd);
}
