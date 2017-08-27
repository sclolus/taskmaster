/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_stop_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 00:43:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 04:01:08 by sclolus          ###   ########.fr       */
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

static inline t_list	*ft_find_control_info(t_list **control_infos
						, t_supervised_program *prog, uint32_t proc_nbr)
{
	t_list	*tmp;

	if (!*control_infos)
		return (NULL);
	tmp = *control_infos;
	while (tmp)
	{
		if (((t_control_info*)tmp->content)->prog == prog
			&& ((t_control_info*)tmp->content)->proc_nbr == proc_nbr)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_task_stop_process(char *instruction, t_list *progs
							, t_list **control_infos)
{
	t_supervised_program	*prog;
	uint32_t				proc_nbr;
	t_list					*tmp;

	if (!(ft_parse_task(instruction, progs, &prog, &proc_nbr)))
		return ;
	if (!(tmp = ft_find_control_info(control_infos, prog, proc_nbr)))
	{
		ft_sock_send("Error: Non-existing process", g_connection->fd);
		return ;
	}
	write(((t_control_info*)tmp->content)->fd[1], &(uint8_t){TASK_STOP}, 1);
	kill(((t_control_info*)tmp->content)->pid, SIGUSR1);
	// wait ?
	ft_remove_control_info_entry(control_infos, tmp);
}
