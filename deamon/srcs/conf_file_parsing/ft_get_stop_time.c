/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stop_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:51:29 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:14:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_stop_time(char *line, uint32_t index
						, t_supervised_program *prog)
{
	index = ft_skip_cmd_header(line, index);
	prog->start_info.stop_time = (uint32_t)ft_atoi(line + index);
	return (1);
}
