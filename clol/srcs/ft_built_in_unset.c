/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:48:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/24 18:48:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t	ft_built_in_unset(char **argv, t_shenv *shenv)
{
	uint32_t	i;

	i = 1;
	while (argv[i])
	{
		if (ft_unset_var(shenv, argv[i]))
			ft_error(3, (char*[])
					{"unset: ", argv[i], " is not a valid set variable name"}
					, EXIT_VAR_NOT_FOUND);
		i++;
	}
	return (0);
}
