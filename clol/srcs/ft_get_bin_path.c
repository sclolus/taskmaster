/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:25:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/08 19:52:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_bin_path(char *pathname, char *filename)
{
	char	*complete_name;

	if (!pathname || !filename)
		return (NULL);
	if (pathname[ft_strlen(pathname) - 1] != '/')
	{
		if (!(complete_name = ft_strjoin(pathname, "/")))
			exit(EXIT_FAILURE);
		if (!(complete_name = ft_strjoin_f(complete_name, filename, 0)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(complete_name = ft_strjoin(pathname, filename)))
			exit(EXIT_FAILURE);
	}
	return (complete_name);
}
