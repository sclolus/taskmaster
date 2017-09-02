/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parser_logicals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:19:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 18:27:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_parser_multiply(t_parser *parser)
{
	t_parser	*new;

	new = ft_get_undefined_parser();
	new->parser.multiply.parser = parser;
	new->parser.multiply.n = 0;
	new->id = MULTIPLY;
	return (new);
}

t_parser	*ft_get_parser_plus(t_parser *parser)
{
	t_parser	*new;

	new = ft_get_undefined_parser();
	new->parser.plus.parser = parser;
	new->parser.plus.n = 0;
	new->id = PLUS;
	return (new);
}

t_parser	*ft_get_parser_and_n(uint32_t n, t_parser **parsers)
{
	t_parser	*parser;
	uint32_t	i;

	i = 0;
	parser = ft_get_undefined_parser();
	if (!(parser->parser.and.parsers = (t_parser**)malloc(sizeof(t_parser*)
														* n)))
		exit(EXIT_FAILURE);
	parser->parser.and.n = n;
	while (i < n)
	{
		parser->parser.and.parsers[i] = parsers[i];
		i++;
	}
	parser->id = AND;
	return (parser);
}

t_parser	*ft_get_parser_or_n(uint32_t n, t_parser **parsers)
{
	t_parser	*parser;
	uint32_t	i;

	i = 0;
	parser = ft_get_undefined_parser();
	if (!(parser->parser.or.parsers = (t_parser**)malloc(sizeof(t_parser*)
														* n)))
		exit(EXIT_FAILURE);
	parser->parser.or.n = n;
	while (i < n)
	{
		parser->parser.or.parsers[i] = parsers[i];
		i++;
	}
	parser->id = OR;
	parser->parser.or.matched = -1;
	return (parser);
}

t_parser	*ft_get_parser_not(t_parser *parser)
{
	t_parser	*new_parser;

	new_parser = ft_get_undefined_parser();
	new_parser->id = NOT;
	new_parser->parser.not.parser = parser;
	return (parser);
}
