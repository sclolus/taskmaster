/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_one_prog.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:17:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 17:59:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline t_list	*ft_parse_one_prog(char *line, uint32_t index)
{
	t_list		*link;

	if (!(link = ft_memalloc(sizeof(t_list)))
		|| !(link->content = ft_memalloc(sizeof(t_supervised_program))))
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	while (ft_parse_one_line(line, index
			, (t_supervised_program*)link->content))
		index = ft_skip_one_line(line, index);
	return (link);
}
