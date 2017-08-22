/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_cmd_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:59:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 19:49:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline uint32_t	ft_skip_cmd_header(char *line, uint32_t index)
{
	uint32_t	i;

	i = index;
	while (line[i] && line[i] != ':')
		i++;
	i++;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	return (i);
}
