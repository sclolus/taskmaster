/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parser_grammar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:59:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 18:59:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_parser_expression(void)
{
	t_parser	*parser;

	parser = ft_get_parser_and_n(2, (t_parser *[])
			{ft_get_parser_list()
			, ft_get_parser_multiply(ft_get_parser_and_n(4, (t_parser *[])
						{ft_get_parser_whitespace()
						, ft_get_parser_onechar('|')
						, ft_get_parser_whitespace()
						, ft_get_parser_list()}))
			});
	if (!(parser->name = ft_strdup("<expression>")))
		exit(EXIT_FAILURE);
	return (parser);
}

t_parser	*ft_get_parser_line_end(void)
{
	t_parser	*eol;

	eol = ft_get_parser_and_n(2, (t_parser *[]){ft_get_parser_whitespace(),
									ft_get_parser_onechar('\n')});
	if (!(eol->name = ft_strdup("<eol>")))
		exit(EXIT_FAILURE);
	return (ft_get_parser_plus(eol));
}

t_parser	*ft_get_parser_rule(void)
{
	t_parser	*parser;

	parser = ft_get_parser_and_n(7, (t_parser*[]){ft_get_parser_whitespace(),
						ft_get_parser_rule_name(), ft_get_parser_whitespace(),
						ft_get_parser_str("::="), ft_get_parser_whitespace(),
						ft_get_parser_expression(), ft_get_parser_line_end()});
	if (!(parser->name = ft_strdup("<rule>")))
		exit(EXIT_FAILURE);
	return (parser);
}

t_parser	*ft_get_parser_syntax(void)
{
	t_parser	*parser;

	parser = ft_get_parser_plus(ft_get_parser_rule());
	ft_set_name_parser(parser, "<syntax>");
	return (parser);
}

t_parser	*ft_get_parser_grammar(void)
{
	t_parser	*syntax;

	syntax = ft_get_parser_syntax();
	return (syntax);
}
