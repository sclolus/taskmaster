/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 01:04:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 04:20:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

static inline void	ft_write_status(t_control_info *control_info, t_instance_status reported_status)
{
	ft_sock_log(6, (const char*[]){PROGRAM(control_info->prog->name)
				, STATUS_LOG(ft_get_status_str(reported_status)), PROCESS_NBR(ft_static_ulltoa(control_info->proc_nbr))}, 0, *g_connection);
	ft_log(6, (const char*[]){PROGRAM(control_info->prog->name)
				, STATUS_LOG(ft_get_status_str(reported_status)), PROCESS_NBR(ft_static_ulltoa(control_info->proc_nbr))});
}

void				ft_task_status(char *instruction, t_list *progs
							, t_list **control_infos)
{
	t_supervised_program	*prog;
	uint32_t				proc_num;
	char					buf;
	t_list					*list;
	int32_t					ret;

	if (!(ret = ft_parse_task(instruction, progs, &prog, &proc_num)))
	{
		list = *control_infos;
		while (list)
		{
			ft_task_request(((t_control_info*)list->content), TASK_STATUS);
			read(((t_control_info*)list->content)->fd[0], &buf, 1);
			ft_write_status(((t_control_info*)list->content), (t_instance_status)buf);
			list = list->next;
		}
	}
	else if (ret)
	{
		if (!(list = ft_find_control_info(control_infos, prog, proc_num)))
		{
			ft_sock_send("Error: Non-existing process: ", g_connection->fd);
			ft_sock_log(6, (const char*[]){"Error: Non-existing process: ", PROGRAM(prog->name)
				, PROCESS_NBR(ft_static_ulltoa(proc_num))}, 0, *g_connection);
			return ;
		}
		ft_task_request(((t_control_info*)list->content), TASK_STATUS);
 		read(((t_control_info*)list->content)->fd[0], &buf, 1);
		ft_write_status(((t_control_info*)list->content), (t_instance_status)buf);
	}
}
