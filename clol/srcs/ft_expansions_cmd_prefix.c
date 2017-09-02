/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansions_cmd_prefix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 08:17:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/15 10:20:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expansions_env_assignment(t_parser *env_assignment,
											t_shenv *shenv)
{
	ft_tilde_expansion(&(AND_PARSER_N(env_assignment,
									2)->parser.str_any_of.str), shenv);
	ft_last_return_value_expansion(&(AND_PARSER_N(env_assignment,
									2)->parser.str_any_of.str));
	ft_var_expansion(&(AND_PARSER_N(env_assignment,
									2)->parser.str_any_of.str), shenv);
	ft_quote_removal(&(AND_PARSER_N(env_assignment,
									2)->parser.str_any_of.str));
}

void		ft_expansions_cmd_prefix(t_parser *cmd_prefix, t_shenv *shenv)
{
	uint32_t	n;
	uint32_t	i;

	i = 0;
	n = MULTIPLY_N(cmd_prefix);
	while (i < n)
	{
		if (IS_RETAINED(OR_PARSER_N(MULTIPLY_PARSER_N(cmd_prefix, i), 0)))
			ft_expansions_env_assignment(
				AND_PARSER_N(OR_PARSER_N(
				MULTIPLY_PARSER_N(cmd_prefix, i), 0), 0), shenv);
		else
			ft_expansions_io_redirect(AND_PARSER_N(
				OR_PARSER_N(MULTIPLY_PARSER_N(cmd_prefix, i), 1), 0), shenv);
		i++;
	}
}
