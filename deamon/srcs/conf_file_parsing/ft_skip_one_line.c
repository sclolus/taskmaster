/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_one_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:56:07 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 17:57:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline uint32_t	ft_skip_one_line(char *line, uint32_t index)
{
	while (line[index] && line[index] != '\n')
		index++;
	index++;
	return (index);
}
