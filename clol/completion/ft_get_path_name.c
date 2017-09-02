/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:14:08 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 00:14:08 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_get_path_name(char *file)
{
	static char	buf[MAX_PATH_NAME];
	uint32_t	i;
	int64_t		offset;

	if (!file && (buf[0] = 0))
		return (NULL);
	i = 0;
	offset = -1;
	while (file[i])
	{
		if (file[i] == '/')
			offset = i;
		i++;
	}
	if (offset > MAX_PATH_NAME - 1)
	{
		return (NULL);
	}
	if (offset >= 0)
	{
		ft_memcpy(buf, file, offset + 1);
		buf[offset + 1] = '\0';
	}
	return (buf);
}
