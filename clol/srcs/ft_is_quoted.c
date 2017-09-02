/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quoted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 05:34:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/08 23:32:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uint32_t	ft_is_escaped(char *input, uint32_t index)
{
	uint32_t	i;
	uint32_t	backslash;

	backslash = 0;
	i = index;
	while (i > 0)
	{
		if (input[i - 1] == '\\')
		{
			backslash ^= 1;
			i--;
		}
		else
			break ;
	}
	return (backslash);
}

uint32_t	ft_is_quoted(char *input, uint32_t index)
{
	uint32_t	i;
	uint32_t	quotes;

	quotes = 0;
	i = 0;
	while (i < index)
	{
		if (input[i] == '\'' && quotes != 2)
			quotes ^= 1;
		else if (input[i] == '\"' && quotes != 1 && !ft_is_escaped(input, i))
			quotes ^= 2;
		i++;
	}
	if (input[i] == '\'' && quotes == 1)
		quotes ^= 1;
	else if (input[i] == '\"' && quotes == 2 && !ft_is_escaped(input, i))
		quotes ^= 2;
	return (quotes);
}
