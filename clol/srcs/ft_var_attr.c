/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 00:52:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/16 05:43:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_var_exported_index(t_shenv *shenv, uint32_t index)
{
	return (shenv->attr[index] == 1);
}

t_bool	ft_is_var_exported(t_shenv *shenv, char *var)
{
	char	**tmp;

	if (!(tmp = ft_find_var(shenv, var)))
		return (0);
	return (shenv->attr[tmp - shenv->var] == 1);
}

t_bool	ft_set_var_to_export(t_shenv *shenv, char *var)
{
	char	**tmp;

	if (!(tmp = ft_find_var(shenv, var)))
		return (0);
	else
		shenv->attr[tmp - shenv->var] = 1;
	return (1);
}
