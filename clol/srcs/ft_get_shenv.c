/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:10:54 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/26 15:12:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shenv		**ft_get_shenv(void)
{
	static t_shenv	*shenv;

	return (&shenv);
}

int32_t		ft_shenv_get_env_count(t_shenv *shenv)
{
	uint32_t	i;
	uint32_t	count;

	i = 0;
	count = 0;
	if (!shenv)
		return (0);
	while (i < shenv->count)
	{
		if (shenv->attr[i])
			count++;
		i++;
	}
	return (count);
}
