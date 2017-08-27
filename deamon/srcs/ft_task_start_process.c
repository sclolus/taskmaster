/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_start_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 23:13:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 01:23:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_task_start_process(char *instruction, t_list *progs
							, t_list **control_infos)
{
	t_supervised_program	*prog;
	t_list					*tmp;
	uint32_t				proc_num;
	t_control_info			info;

	ft_parse_task(instruction, progs, &prog, &proc_num);
	info = ft_create_control_fork(g_connection, prog, proc_num); // asdafsdf
	if (!info.prog)
		return ;
	if (!(tmp = ft_lstnew(&info, sizeof(t_control_info))))
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	ft_lstadd(control_infos, tmp);
}
