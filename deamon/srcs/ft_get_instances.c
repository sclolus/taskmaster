/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:47:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 10:49:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

t_mem_block	*ft_get_instances(void)
{
	static t_mem_block	*instances = NULL;

	if (!instances)
		instances = ft_create_mem_block(DEFAULT_MEM_BLOCK_SIZE);
	return (instances);
}
