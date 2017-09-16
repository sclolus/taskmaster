/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:32:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 01:04:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_task_execution(char *instruction, t_list *progs)
{
	static t_instruction instructions[] =
	{
		{"exit", &ft_task_instance_exit},
		{"start", &ft_task_start_process},
		{"stop", &ft_task_stop_process},
		{"restart", &ft_task_restart_process},
		{"stop_all", &ft_task_stop_all},
		{"status", &ft_task_status},
	};
	static t_list	*control_infos = NULL;
	uint32_t	i;

	i = 0;
	while (i < sizeof(instructions) / sizeof(t_instruction))
	{
		if (ft_strnequ(instruction, instructions[i].id, ft_strlen(instructions[i].id)))
		{
			instructions[i].f(instruction, progs, &control_infos);
			return ;
		}
		i++;
	}
	ft_sock_send("Command not found: ", g_connection->fd);
	ft_sock_send(instruction, g_connection->fd);
}
