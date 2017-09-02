/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_t_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 06:08:13 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/20 06:11:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_refresh_t_tokens_lens(t_tokens *tokens, uint32_t index
									, char *ptr, uint32_t token_count)
{
	static uint32_t	lens[3];
	uint32_t		*new_lens;

	lens[0] = ptr - tokens->tokens[index];
	lens[1] = 1;
	lens[2] = tokens->lens[index] - lens[0] - 1;
	if (!(new_lens = ft_memalloc(sizeof(uint32_t) * (token_count + 2 + 1))))
		exit(EXIT_FAILURE);
	ft_memcpy(new_lens, tokens->lens, index * sizeof(uint32_t));
	ft_memcpy(new_lens + index, lens, 3 * sizeof(uint32_t));
	ft_memcpy(new_lens + index + 3, tokens->lens + index + 1
			, (token_count - index - 1) * sizeof(uint32_t));
	free(tokens->lens);
	tokens->lens = new_lens;
}

void	ft_refresh_t_tokens_tokens(t_tokens *tokens, uint32_t index
									, uint32_t token_count)
{
	static char		*tmp[3];
	char			**new_tokens;

	if (!(tmp[0] = ft_strndup(tokens->tokens[index], tokens->lens[index]))
		|| !(tmp[1] = ft_strdup("="))
		|| !(tmp[2] = ft_strdup(tokens->tokens[index]
								+ tokens->lens[index] + 1)))
		exit(EXIT_FAILURE);
	if (!(new_tokens = ft_memalloc(sizeof(char*) * (token_count + 3))))
		exit(EXIT_FAILURE);
	ft_memcpy(new_tokens, tokens->tokens, index * sizeof(char*));
	ft_memcpy(new_tokens + index, tmp, 3 * sizeof(char*));
	ft_memcpy(new_tokens + index + 3, tokens->tokens + index + 1
			, (token_count - index - 1) * sizeof(char*));
	free(tokens->tokens[index]);
	free(tokens->tokens);
	tokens->tokens = new_tokens;
}
