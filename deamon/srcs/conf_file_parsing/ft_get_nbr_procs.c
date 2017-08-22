/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_procs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:50:07 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:12:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_nbr_procs(char *line, uint32_t index
						, t_supervised_program *prog)
{
	uint32_t	i;

	i = index;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	prog->start_info.process_nbr = (uint32_t)ft_atoi(line + i);
	return (1);
}
