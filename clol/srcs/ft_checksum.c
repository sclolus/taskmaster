/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 05:58:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/07 06:02:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uint64_t	ft_checksum(char *string)
{
	uint32_t	i;
	uint32_t	checksum;

	i = 0;
	checksum = (((~0) / 255) * 123) >> 21;
	while (string[i])
	{
		checksum += ((string[i] << 3) + i) >> 2;
		i++;
	}
	return (checksum);
}
