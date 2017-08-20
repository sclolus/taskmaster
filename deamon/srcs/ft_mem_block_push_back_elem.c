/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_block_push_back_elem.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:04:28 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 08:18:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size)
{
	while (mem_block->next)
		mem_block = mem_block->next;
	if (mem_block->offset + size <= mem_block->capacity)
	{
		ft_memcpy((unsigned char*)mem_block->block
				+ mem_block->offset, elem, size);
		mem_block->offset += size;
	}
	else
	{
		mem_block->next = ft_create_mem_block(DEFAULT_MEM_BLOCK_SIZE);
		return (ft_mem_block_push_back_elem(mem_block->next, elem, size));
	}
	return (mem_block + mem_block->offset - size);
}
