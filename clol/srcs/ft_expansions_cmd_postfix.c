/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansions_cmd_postfix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 08:19:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/15 10:21:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expansions_arg(t_parser *arg, t_shenv *shenv)
{
	ft_tilde_expansion(&arg->parser.str_any_of.str, shenv);
	ft_last_return_value_expansion(&arg->parser.str_any_of.str);
	ft_var_expansion(&arg->parser.str_any_of.str, shenv);
	ft_quote_removal(&arg->parser.str_any_of.str);
}

void		ft_expansions_cmd_postfix(t_parser *cmd_postfix, t_shenv *shenv)
{
	uint32_t	n;
	uint32_t	i;

	i = 0;
	n = MULTIPLY_N(cmd_postfix);
	while (i < n)
	{
		if (IS_RETAINED(OR_PARSER_N(AND_PARSER_N(MULTIPLY_PARSER_N(cmd_postfix,
																	i), 0), 1)))
			ft_expansions_arg(OR_PARSER_N(AND_PARSER_N(
					MULTIPLY_PARSER_N(cmd_postfix, i), 0), 1), shenv);
		else
			ft_expansions_io_redirect(OR_PARSER_N(AND_PARSER_N(
					MULTIPLY_PARSER_N(cmd_postfix, i), 0), 0), shenv);
		i++;
	}
}
