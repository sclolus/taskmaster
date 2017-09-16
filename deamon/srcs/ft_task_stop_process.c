/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_stop_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 00:43:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 04:21:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

static inline void	ft_remove_control_info_entry(t_list **control_infos
										, t_list *to_remove)
{
	t_list	*tmp;
	t_list	*last;

	if (!*control_infos)
		return ;
	tmp = *control_infos;
	last = NULL;
	while (tmp)
	{
		if (to_remove == tmp)
		{
			free(tmp->content);
			if (last)
				last->next = tmp->next;
			else
				*control_infos = tmp->next;
			free(tmp);
			return ;
		}
		last = tmp;
		tmp = tmp->next;
	}
}

void	ft_task_stop_process(char *instruction, t_list *progs
							, t_list **control_infos)
{
	t_supervised_program	*prog;
	uint32_t				proc_nbr;
	t_list					*tmp;
	int						ret;

	if (1 < (ft_parse_task(instruction, progs, &prog, &proc_nbr)))
		return ;
	if (!(tmp = ft_find_control_info(control_infos, prog, proc_nbr)))
	{
		ft_sock_send("Error: Non-existing process", g_connection->fd);
		return ;
	}
	ft_task_request(((t_control_info*)tmp->content), TASK_STOP);
	waitpid(((t_control_info*)tmp->content)->pid, &ret, WUNTRACED);
	if (WIFEXITED(ret))
	{
		ft_sock_log(4, (const char*[]){STOPPED_PROCESS, prog->name
					, PROCESS_NBR(ft_static_ulltoa(proc_nbr))}, 0, *g_connection);
		ft_log(4, (const char*[]){STOPPED_PROCESS, prog->name
					, PROCESS_NBR(ft_static_ulltoa(proc_nbr))});
	}
	ft_remove_control_info_entry(control_infos, tmp);
}
