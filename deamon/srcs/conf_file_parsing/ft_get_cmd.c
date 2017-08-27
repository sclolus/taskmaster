/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:46:13 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:33:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_cmd(char *line, uint32_t index
						, t_supervised_program *prog)
{
	uint32_t	i;

	index = ft_skip_cmd_header(line, index);
	i = index + 1;
	while (line[i] && line[i] != '\"')
		i++;
	line[i] = '\0';
	if (!(prog->start_info.cmd = ft_strsplit(line + index + 1, ' ')))
	{
		// ft_close_connection();
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	}
	line[i] = '0';
	return (1);
}
