/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parsing_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:55:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:12:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline char	*ft_get_parsing_path(char *line, uint32_t index)
{
	char		*path;
	uint32_t	i;
	uint32_t	len;

	i = index;
	len = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
		len++;
	}
	if (!(path = ft_strndup(line + i - len, len)))
		ft_error_exit(1, (char*[]){MALLOC_FAILURE}, EXIT_FAILURE);
	return (path);
}
