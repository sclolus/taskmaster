/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_one_prog.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:04:54 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:07:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline uint32_t	ft_skip_one_prog(char *buffer, uint32_t i)
{
	i = ft_skip_one_line(buffer, i);
	while (buffer[i] && ft_strnequ(buffer + i, "\t\t", 2))
		i = ft_skip_one_line(buffer, i);
	return (i);
}
