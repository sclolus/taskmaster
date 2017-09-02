/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:31:24 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/18 23:22:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	*ft_t_process_add(t_process **processes, t_process *new)
{
	new->next = *processes;
	*processes = new;
	if (new->next)
		new->next->prev = new;
	(*processes)->prev = NULL;
	return (new);
}

void		ft_clear_processes(t_process **processes)
{
	t_process	*curr_process;
	t_process	*tmp;

	curr_process = *processes;
	kill(-curr_process->gpid, SIGKILL);
	while (curr_process)
	{
		kill(curr_process->pid, SIGKILL);
		free(curr_process->argv);
		tmp = curr_process;
		if (curr_process->next)
			waitpid(curr_process->pid, NULL, 0);
		curr_process = curr_process->next;
		free(tmp);
	}
}

void		ft_put_processes_in_foreground(t_process *process, int cont)
{
	ft_unset_term();
	ft_unset_insert();
	tcsetpgrp(g_shell->terminal, process->gpid);
	if (cont)
		kill(-process->gpid, SIGCONT);
}
