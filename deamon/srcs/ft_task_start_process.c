/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_start_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 23:13:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 03:38:31 by sclolus          ###   ########.fr       */
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

	printf("parsed: %s\n", instruction);
	if (-1 == (ft_parse_task(instruction, progs, &prog, &proc_num)))
		return ;
	info = ft_create_control_fork(g_connection, prog, proc_num); // asdafsdf
	if (!info.prog)
		return ;
	if (!(tmp = ft_lstnew(&info, sizeof(t_control_info))))
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	ft_lstadd(control_infos, tmp);
	ft_log(4, (const char*[]){"Started program: ", prog->name
				, ", process number: ", ft_static_ulltoa(proc_num)});
}
