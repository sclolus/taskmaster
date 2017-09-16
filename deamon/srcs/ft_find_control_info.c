/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_control_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 02:43:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 02:43:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline t_list	*ft_find_control_info(t_list **control_infos
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
