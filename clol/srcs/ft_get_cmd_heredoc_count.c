/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_heredoc_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:11:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/28 18:59:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static uint32_t		ft_is_redirection_heredoc(t_parser *io_redirect)
{
	if (IS_RETAINED(OR_PARSER_N(io_redirect, 0)))
	{
		io_redirect = AND_PARSER_N(OR_PARSER_N(io_redirect, 0), 1);
		if (IS_RETAINED(OR_PARSER_N(io_redirect, 4)))
			return (1);
		return (0);
	}
	else
	{
		io_redirect = OR_PARSER_N(io_redirect, 1);
		if (IS_RETAINED(OR_PARSER_N(io_redirect, 4)))
			return (1);
		return (0);
	}
}

static uint32_t		ft_get_cmd_prefix_heredoc_count(t_parser *cmd_prefix)
{
	uint32_t	i;
	uint32_t	n;
	uint32_t	count;

	count = 0;
	i = 0;
	n = MULTIPLY_N(cmd_prefix);
	while (i < n)
	{
		if (IS_RETAINED(OR_PARSER_N(MULTIPLY_PARSER_N(cmd_prefix, i), 1))
			&& ft_is_redirection_heredoc(AND_PARSER_N(OR_PARSER_N(
				MULTIPLY_PARSER_N(cmd_prefix, i), 1), 0)))
			count++;
		i++;
	}
	return (count);
}

static uint32_t		ft_get_cmd_postfix_heredoc_count(t_parser *cmd_postfix)
{
	uint32_t	i;
	uint32_t	n;
	uint32_t	count;

	count = 0;
	i = 0;
	n = MULTIPLY_N(cmd_postfix);
	while (i < n)
	{
		if (IS_RETAINED(OR_PARSER_N(AND_PARSER_N(MULTIPLY_PARSER_N(
			cmd_postfix, i), 0), 0)) && ft_is_redirection_heredoc(
			OR_PARSER_N(MULTIPLY_PARSER_N(cmd_postfix, i), 0)))
			count++;
		i++;
	}
	return (count);
}

uint32_t			ft_get_cmd_heredoc_count(t_parser *simple_cmd)
{
	uint32_t	count;

	count = 0;
	if (IS_RETAINED(OR_PARSER_N(simple_cmd, 0)))
	{
		simple_cmd = OR_PARSER_N(simple_cmd, 0);
		count += ft_get_cmd_prefix_heredoc_count(AND_PARSER_N(simple_cmd, 1));
		count += ft_get_cmd_postfix_heredoc_count(AND_PARSER_N(simple_cmd, 4));
	}
	else
	{
		simple_cmd = OR_PARSER_N(simple_cmd, 1);
		count += ft_get_cmd_prefix_heredoc_count(AND_PARSER_N(simple_cmd, 0));
	}
	return (count);
}
