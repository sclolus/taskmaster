/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_working_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:52:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:14:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_working_dir(char *line, uint32_t index
						, t_supervised_program *prog)
{
	uint32_t	i;

	i = index;
	while (line[i] && line[i] != ':')
		i++;
	i++;
	prog->start_info.working_dir = ft_get_parsing_path(line, i);
	return (1);
}
