/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 16:21:16 by aalves            #+#    #+#             */
/*   Updated: 2017/05/08 19:52:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char			*ft_find_command(char *filename, char **path)
{
	uint32_t	i;
	char		*bin_path;

	i = 0;
	*filename == '/' ? filename++ : 0;
	if (!path)
		return (NULL);
	while (path[i])
	{
		if (!(bin_path = ft_get_bin_path(path[i], filename)))
			return (NULL);
		if (ft_check_file(bin_path))
		{
			if (ft_check_exec_perm(bin_path))
				return (path[i]);
			else
			{
				ft_error(2, (char*[]){filename, ": Permission denied"}, -1);
				return (NULL);
			}
		}
		free(bin_path);
		i++;
	}
	return (NULL);
}
