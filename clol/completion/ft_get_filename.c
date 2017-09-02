/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:13:54 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 00:13:55 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_get_file_name(char *file)
{
	static char	buf[MAX_FILE_NAME];
	uint32_t	i;
	uint32_t	len;
	int64_t		offset;

	if (!file)
		return (NULL);
	i = 0;
	offset = -1;
	len = ft_strlen(file);
	while (file[i])
	{
		if (file[i] == '/')
			offset = i;
		i++;
	}
	if (len - offset > MAX_FILE_NAME)
	{
		ft_putstr_fd("Filename too long\n", 2);
		return (NULL);
	}
	ft_memcpy(buf, file + offset + 1, len - offset);
	buf[len - offset] = 0;
	return (buf);
}
