/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prog_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:41:44 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:48:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_prog_name(char *line, uint32_t index
						, t_supervised_program *prog)
{
	uint32_t	i;
	uint32_t	len;

	i = index;
	while (line[i] && line[i] == '\t')
		i++;
	len = 0;
	while (line[i] && line[i] != ':')
	{
		i++;
		len++;
	}
	if (!(prog->name = ft_strndup(line + i - len, len)))
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	return (1);
}
