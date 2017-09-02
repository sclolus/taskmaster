/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grammar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 04:43:56 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 16:38:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_grammar_literal(t_parser *literal)
{
	t_parser	*parser;
	t_parser	*tmp;

	if (literal->parser.or.parsers[0]->retained)
	{
		tmp = literal->parser.or.parsers[0]->parser.and.parsers[1];
		parser = ft_get_parser_str(tmp->parser.str_any.str);
	}
	else if (literal->parser.or.parsers[1]->retained)
	{
		tmp = literal->parser.or.parsers[1]->parser.and.parsers[1];
		parser = ft_get_parser_onechar(tmp->parser.any.matched);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (parser);
}

t_parser	*ft_get_grammar_term(t_parser *term)
{
	if (term->parser.or.parsers[0]->retained)
		return (ft_get_grammar_literal(term->parser.or.parsers[0]));
	else if (term->parser.or.parsers[1]->retained)
	{
		return (ft_get_parser_ref(
		term->parser.or.parsers[1]->parser.and.parsers[1]->parser.str_any.str));
	}
	else
	{
		if (term->parser.or.parsers[2]->parser.and.parsers[6]->parser.oneof.c
			== '*')
			return (ft_get_parser_multiply(ft_get_grammar_expression(
term->parser.or.parsers[2]->parser.and.parsers[3]->parser.func.parser)));
		else
			return (ft_get_parser_plus(ft_get_grammar_expression(
				term->parser.or.parsers[2]
				->parser.and.parsers[3]->parser.func.parser)));
	}
}

t_parser	*ft_get_grammar_list(t_parser *list)
{
	t_parser	*parser;
	t_parser	**parsers;
	uint32_t	i;

	i = 0;
	if (list->parser.plus.n == 1)
	{
		return (ft_get_grammar_term(
				list->parser.plus.parsers[0]->parser.and.parsers[0]));
	}
	if (!(parsers = (t_parser**)malloc(
			sizeof(t_parser*) * list->parser.plus.n)))
		exit(EXIT_FAILURE);
	while (i < list->parser.plus.n)
	{
		parsers[i] = ft_get_grammar_term(
			list->parser.plus.parsers[i]->parser.and.parsers[0]);
		i++;
	}
	parser = ft_get_parser_and_n(list->parser.plus.n, parsers);
	free(parsers);
	return (parser);
}

t_parser	*ft_get_grammar_expression(t_parser *expression)
{
	uint32_t	size;

	size = expression->parser.and.parsers[1]->parser.multiply.n;
	if (size)
	{
		return (ft_get_grammar_or_n(size + 1, expression->parser.and.parsers[0]
		, expression->parser.and.parsers[1]->parser.multiply.parsers));
	}
	else
		return (ft_get_grammar_list(expression->parser.and.parsers[0]));
}

t_parser	*ft_get_grammar_rule(t_parser *rule)
{
	t_parser	*parser;

	parser = ft_get_grammar_expression(rule->parser.and.parsers[5]);
	parser->name = ft_strndup(
	rule->parser.and.parsers[1]->parser.and.parsers[1]->parser.str_any.str
	, rule->parser.and.parsers[1]->parser.and.parsers[1]->parser.str_any.len);
	return (parser);
}
