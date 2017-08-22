/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prog_name_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:17:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 19:47:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

int32_t	ft_is_prog_name_case(char *line, uint32_t index
							, t_supervised_program *prog)
{
	if (prog->name)
		return (0);
	if (ft_strnequ(line + index, "\t", 1))
	{
		index = ft_skip_cmd_header(line, index);
		if (line[index] == '\n')
			return (1);
	}
	return (0);
}
