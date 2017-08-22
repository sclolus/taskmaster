/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:46:13 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:02:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_cmd(char *line, uint32_t index
						, t_supervised_program *prog)
{
	uint32_t	i;
	uint32_t	len;

	i = index;
	while (line[i] && line[i] != '\"')
		i++;
	len = 0;
	while (line[i] && line[i] != '\"')
	{
		i++;
		len++;
	}
	if (!(prog->start_info.cmd = ft_strndup(line + i - len, len)))
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	return (1);
}
