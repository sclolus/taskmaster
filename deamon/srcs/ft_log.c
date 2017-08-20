/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:47:38 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 10:55:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_log(uint32_t n, const char * const *strings)
{
	uint32_t	i;

	i = 0;
	while (i < n)
		ft_putstr(strings[i++]);
	ft_putendl("");
}
