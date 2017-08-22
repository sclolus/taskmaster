/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start_retries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:35:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:12:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_start_retries(char *line, uint32_t index
						, t_supervised_program *prog)
{
	index = ft_skip_cmd_header(line, index);
	prog->start_info.start_retries = (uint32_t)ft_atoi(line + index);
	return (1);
}
