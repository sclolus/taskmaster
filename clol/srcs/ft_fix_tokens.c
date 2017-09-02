/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 01:47:43 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/20 06:11:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_is_var_assignment(t_tokens *tokens, uint32_t index)
{
	uint32_t	i;
	char		*ptr;

	i = 0;
	if (!(ptr = ft_strchr(tokens->tokens[index], '='))
		|| ft_is_quoted(tokens->tokens[index], ptr - tokens->tokens[index])
		|| !ft_strcmp(tokens->tokens[index], "="))
		return (NULL);
	while (tokens->tokens[index] + i != ptr)
	{
		if (!(tokens->tokens[index][i] >= 'A'
			&& tokens->tokens[index][i] <= 'Z')
			&& !ft_isdigit(tokens->tokens[index][i])
			&& tokens->tokens[index][i] != '_')
			return (NULL);
		i++;
	}
	return (ptr);
}

static uint32_t	ft_get_t_tokens_count(t_tokens *tokens)
{
	uint32_t	i;

	i = 0;
	while (tokens->tokens[i])
		i++;
	return (i);
}

static void		ft_sanitize_var_assignment_tokens(t_tokens *tokens
									, uint32_t index, char *ptr)
{
	uint32_t	token_count;

	token_count = ft_get_t_tokens_count(tokens);
	ft_refresh_t_tokens_lens(tokens, index, ptr, token_count);
	ft_refresh_t_tokens_tokens(tokens, index, token_count);
}

static void		ft_reset_state(t_bool *state, char *token)
{
	if (!ft_strcmp("&&", token)
		|| !ft_strcmp("||", token)
		|| !ft_strcmp(";", token)
		|| !ft_strcmp("&", token)
		|| !ft_strcmp("|", token))
		*state = 1;
}

void			ft_fix_tokens(t_tokens *tokens)
{
	char		*ptr;
	uint32_t	i;
	t_bool		state;

	i = 0;
	state = 1;
	while (tokens->tokens[i])
	{
		if ((ptr = ft_is_var_assignment(tokens, i)) && state)
		{
			ft_sanitize_var_assignment_tokens(tokens, i, ptr);
			i += 3;
			continue ;
		}
		else
			state = 0;
		ft_reset_state(&state, tokens->tokens[i]);
		i++;
	}
}
