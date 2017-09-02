/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:01:46 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 23:03:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uint32_t		ft_get_tokens_count(char **tokens)
{
	uint32_t	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

t_tokens		*ft_get_tokens(char *input)
{
	t_tokens	*tokens;
	uint32_t	i;
	uint32_t	count;

	if (!(tokens = (t_tokens*)ft_memalloc(sizeof(t_tokens))))
		exit(EXIT_FAILURE);
	if (!(tokens->tokens = ft_lexer(input)))
	{
		free(tokens);
		return (NULL);
	}
	count = ft_get_tokens_count(tokens->tokens);
	if (!(tokens->lens = (uint32_t*)ft_memalloc(sizeof(uint32_t) * count)))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < count)
	{
		tokens->lens[i] = ft_strlen(tokens->tokens[i]);
		i++;
	}
	return (tokens);
}
