/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_removal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:39:20 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/11 05:11:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_sanitize_backslashes(char *word)
{
	uint32_t	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '\\' && ft_strchr(CHARSET_ESCAPE_BCKSLH, word[i + 1])
			&& ft_is_quoted(word, i) != 1)
			ft_strcpy(word + i, word + i + 1);
		++i;
	}
}

static uint32_t		ft_sanitize_quotes(char *word, uint32_t *indexes
									, uint32_t offset, uint32_t i)
{
	uint32_t	u;

	u = 0;
	while (u + 1 < offset)
	{
		ft_memcpy(word + indexes[u] - u
				, word + indexes[u] + 1, indexes[u + 1] - indexes[u]);
		u++;
	}
	if (offset)
	{
		ft_strcpy(word + indexes[u] - u
				, word + indexes[u] + 1);
	}
	return (i - offset);
}

void				ft_quote_removal(char **word)
{
	static uint32_t		indexes[QUOTE_REMOVAL_BUFF_SIZE];
	uint32_t			offset;
	uint32_t			i;
	uint32_t			last_unquoted_point;
	uint32_t			is_quoted;

	i = 0;
	last_unquoted_point = 0;
	offset = 0;
	while (word[0][i])
	{
		is_quoted = ft_is_quoted(*word + last_unquoted_point
								, i - last_unquoted_point);
		if ((ft_strchr(CHARSET_QUOTES, word[0][i])
			&& !is_quoted))
			indexes[offset++] = i;
		if (offset == QUOTE_REMOVAL_BUFF_SIZE)
		{
			i = ft_sanitize_quotes(*word, indexes, offset, i);
			offset = 0;
		}
		i++;
	}
	ft_sanitize_quotes(*word, indexes, offset, i);
	ft_sanitize_backslashes(*word);
}
