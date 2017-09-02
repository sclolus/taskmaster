/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_unsetenv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 07:03:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/24 18:35:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t	ft_built_in_unsetenv(char **argv, t_shenv *shenv)
{
	uint32_t	i;

	i = 1;
	while (argv[i])
	{
		if (ft_unset_var(shenv, argv[i]))
			ft_error(3, (char*[])
					{"unsetenv: ", argv[i], " is not a valid set variable name"}
					, EXIT_VAR_NOT_FOUND);
		i++;
	}
	return (0);
}
