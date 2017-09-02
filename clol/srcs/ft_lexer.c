/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:38:07 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/20 01:46:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int32_t	ft_is_shell_reserved(char *buf, uint32_t i)
{
	if (ft_strchr("|&;<> \t\n", buf[i])
		&& !ft_is_quoted(buf, i))
		return (1);
	return (0);
}

uint32_t		ft_is_part_of_op(char *input, uint32_t index)
{
	uint32_t	i;

	i = index;
	if (i > 0 && !ft_is_quoted(input, index - 1)
		&& ft_strchr("|&;<>", input[index - 1]))
		return (1);
	else
		return (0);
}

static uint32_t	ft_delimite_tokens(char *input, uint32_t i,
										t_bool bool_word)
{
	if (!bool_word && !ft_strchr(CHARSET_WHITESPACES, input[i]))
		return (2);
	else if (bool_word && ((ft_strchr(CHARSET_WHITESPACES, input[i])
							&& !ft_is_quoted(input, i))
							|| (!ft_is_shell_reserved(input, i)
							&& ft_is_part_of_op(input, i))))
		return (1);
	else if (bool_word && ft_is_shell_reserved(input, i)
			&& !ft_is_part_of_op(input, i))
		return (1);
	return (0);
}

char			**ft_lexer(char *input)
{
	t_list		*token_list;
	uint32_t	i;
	uint32_t	start;
	t_bool		bool_word;
	uint32_t	ret;

	i = 0;
	start = 0;
	bool_word = 0;
	token_list = NULL;
	while (input[i])
	{
		if ((ret = ft_delimite_tokens(input, i, bool_word)) == 1)
		{
			bool_word = 0;
			ft_add_token_to_list(&token_list, input, start, i);
			continue ;
		}
		else if (ret == 2 && (bool_word = 1))
			start = i;
		i++;
	}
	if (bool_word)
		ft_add_token_to_list(&token_list, input, start, i);
	return (ft_token_list_to_tab(token_list));
}
