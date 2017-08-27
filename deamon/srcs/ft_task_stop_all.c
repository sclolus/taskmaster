/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_stop_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 01:08:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 01:25:22 by sclolus          ###   ########.fr       */
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
		}
		last = tmp;
		tmp = tmp->next;
	}
}

void				ft_task_stop_all(char *instruction, t_list *progs
							, t_list **control_infos)
{
	t_list	*tmp;

	(void)instruction;
	(void)progs;
	if (!*control_infos)
		return ;
	tmp = *control_infos;
	while (tmp)
	{
		write(((t_control_info*)tmp->content)->fd[1], &(uint8_t){TASK_STOP}, 1);
		kill(((t_control_info*)tmp->content)->pid, SIGUSR1);
		ft_remove_control_info_entry(control_infos, tmp);
		tmp = tmp->next;
	}
}
