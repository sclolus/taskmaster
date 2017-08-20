/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:39:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 10:56:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_mark_instance(pid_t pid, t_instance_status status)
{
	t_mem_block	*instances;
	uint32_t	i;

	instances = ft_get_instances();
	i = 0;
	while (i * sizeof(t_instance) < instances->offset)
	{
		if (pid == ((t_instance*)instances->block + i)->pid)
		{
			((t_instance*)instances->block + i)->status = status;
			ft_log(2, (const char*[]){"Instance marked as: "
						, ft_get_status_str(status)});
			return ;
		}
		i++;
		if (i * sizeof(t_instance) >= instances->offset && instances->next)
		{
			instances = instances->next;
			i = 0;
		}
	}
	ft_error(1, (char*[]){"Instance not found"}, 1);
}
