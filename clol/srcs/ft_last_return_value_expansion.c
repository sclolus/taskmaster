/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_return_value_expansion.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:08:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/15 10:30:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static uint32_t	ft_is_var_quoted(char *word, uint32_t index)
{
	return ((ft_is_quoted(word, index) != 1
			&& !ft_is_escaped(word, index)));
}

void			ft_last_return_value_expansion(char **word)
{
	char		*tmp;
	char		*var_value;
	uint32_t	i;

	i = 0;
	while (word[0][i])
	{
		if (word[0][i] == '$' && ft_is_var_quoted(*word, i)
			&& !ft_strncmp(word[0] + i, "$?", 2))
		{
			tmp = *word;
			if (!(var_value = ft_itoa(*ft_get_last_return_value())))
				exit(EXIT_FAILURE);
			*word = ft_strreplace(tmp, i
								, i + 2 + 1, var_value);
			free(var_value);
			free(tmp);
		}
		i++;
	}
}
