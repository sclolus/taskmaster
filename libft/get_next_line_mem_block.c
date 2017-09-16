/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mem_block.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 21:33:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/03 22:09:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define DEFAULT_GNL_BLOCK_SIZE (2 << 32)
int				get_next_line_mem_block(const int fd, char **line)
{
	static uint64_t		current_index = 0;
	static t_mem_block	*lines = NULL;
	static char			buf[BUFF_SIZE + 1];
	char				*tmp;
	ssize_t				ret;

	if (!lines)
		lines = ft_create_mem_block(DEFAULT_GNL_BLOCK_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_mem_block_push_back_elem(lines, buf, ret);
		if ((tmp = ft_strchr(lines->block + current_index, '\n')))
		{
			current_index
		}
	}
	if (ret < 1)
		return (ret);

}
