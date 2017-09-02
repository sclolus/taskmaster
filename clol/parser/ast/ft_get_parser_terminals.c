/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parser_terminals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:59:53 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:00:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_parser_term(void)
{
	t_parser	*parser;

	parser = ft_get_parser_or_n(3, (t_parser *[]){ft_get_parser_literal(),
												ft_get_parser_rule_name(),
												ft_get_parser_invocations()});
	ft_set_name_parser(parser, "<term>");
	return (parser);
}

t_parser	*ft_get_parser_literal(void)
{
	t_parser	*parser;

	parser = ft_get_parser_or_n(2, (t_parser *[])
			{ft_get_parser_and_n(3, (t_parser *[]){ft_get_parser_onechar('\"')
			, ft_get_parser_str_any(), ft_get_parser_onechar('\"')})
			, ft_get_parser_and_n(3, (t_parser *[]){ft_get_parser_onechar('\'')
			, ft_get_parser_any(), ft_get_parser_onechar('\'')})});
	if (!(parser->name = ft_strdup("<parser_literal>")))
		exit(EXIT_FAILURE);
	return (parser);
}

t_parser	*ft_get_parser_rule_name(void)
{
	t_parser	*parser;

	parser = ft_get_parser_and_n(3, (t_parser *[]){ft_get_parser_onechar('<')
					, ft_get_parser_str_any()
					, ft_get_parser_onechar('>')});
	if (!(parser->name = ft_strdup("<rule_name>")))
		exit(EXIT_FAILURE);
	return (parser);
}

t_parser	*ft_get_parser_list(void)
{
	t_parser	*parser;

	parser = ft_get_parser_plus(ft_get_parser_and_n(2,
		(t_parser *[]){ft_get_parser_term(), ft_get_parser_whitespace()}));
	if (!(parser->name = ft_strdup("<list>")))
		exit(EXIT_FAILURE);
	return (parser);
}

t_parser	*ft_get_parser_invocations(void)
{
	t_parser	*parser;

	parser = ft_get_parser_and_n(8, (t_parser *[]){ft_get_parser_whitespace(),
		ft_get_parser_onechar('('), ft_get_parser_whitespace(),
		ft_get_parser_func(&ft_get_parser_expression, &ft_eval_delayed),
		ft_get_parser_whitespace(), ft_get_parser_onechar(')'),
		ft_get_parser_oneof("+*"), ft_get_parser_whitespace()});
	ft_set_name_parser(parser, "<invocations>");
	return (parser);
}
