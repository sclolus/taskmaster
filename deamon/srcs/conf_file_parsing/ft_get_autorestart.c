/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_autorestart.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:58:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:10:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_autorestart(char *line, uint32_t index
						, t_supervised_program *prog)
{
	static char	*values[] = {"false", "true"};
	uint32_t	i;

	index = ft_skip_cmd_header(line, index);
	i = 0;
	while (i < sizeof(values) / sizeof(char*))
	{
		if (ft_strnequ(line + index, values[i], ft_strlen(values[i])))
		{
			prog->process_flags.bits.autorestart = (uint16_t)i;
			return (1);
		}
		i++;
	}
	return (0);
}
