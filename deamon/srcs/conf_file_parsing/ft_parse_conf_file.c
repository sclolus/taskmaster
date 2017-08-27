/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conf_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:12:05 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:26:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

t_list	*ft_parse_conf_file(char *buffer)
{
	t_list		*supervised_progs;
	uint32_t	i;

	supervised_progs = NULL;
	if (!buffer)
	{
		ft_error(1, (char*[]){PARSE_CONF_FILE_ERR}, 0);
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i])
	{
		ft_lstadd(&supervised_progs, ft_parse_one_prog(buffer, i));
		i = ft_skip_one_prog(buffer, i);
	}
	free(buffer);
	return (supervised_progs);
}
