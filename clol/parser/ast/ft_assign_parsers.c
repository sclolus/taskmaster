/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:24:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 21:28:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_parser		*ft_assign_parser_data_and_or(t_parser *parser
												, t_parser *new_parser)
{
	t_parser	*tmp;
	uint32_t	i;

	if (!(new_parser->parser.and.parsers = (t_parser**)malloc(
			sizeof(t_parser*) * parser->parser.and.n)))
		exit(EXIT_FAILURE);
	tmp = new_parser;
	i = 0;
	while (i < parser->parser.and.n)
	{
		if (!parser->parser.and.parsers[i])
			new_parser->parser.and.parsers[i] = NULL;
		else
			new_parser->parser.and.parsers[i] = tmp + 1;
		tmp = ft_assign_parsers(parser->parser.and.parsers[i++], tmp + 1);
	}
	return (tmp);
}

static t_parser		*ft_assign_parser_data(t_parser *parser
										, t_parser *new_parser)
{
	uint32_t	i;

	i = 0;
	if (!parser)
		return (NULL);
	if (parser->id == FUNC)
		return (new_parser);
	else if (parser->id == AND || parser->id == OR)
		return (ft_assign_parser_data_and_or(parser, new_parser));
	else if (parser->id == NOT || parser->id == PLUS || parser->id == MULTIPLY)
	{
		new_parser->parser.not.parser = new_parser + 1;
		return (ft_assign_parsers(parser->parser.not.parser, new_parser + 1));
	}
	else
		return (ft_assign_parsers(parser->parser.not.parser, new_parser + 1));
}

static t_parser		*ft_assign_unary_parsers(t_parser *parser
											, t_parser *new_parser)
{
	if (parser->id == STRING)
		!(new_parser->parser.string.str = ft_strdup(parser->parser.string.str))
			? exit(EXIT_FAILURE) : 0;
	else if (parser->id == ONEOF)
		!(new_parser->parser.oneof.charset = ft_strdup(
			parser->parser.oneof.charset))
			? exit(EXIT_FAILURE) : 0;
	else if (parser->id == STR_ANY_OF)
		!(new_parser->parser.str_any_of.charset = ft_strdup(
			parser->parser.str_any_of.charset))
			? exit(EXIT_FAILURE) : 0;
	else if (parser->id == REF)
		!(new_parser->parser.ref.rule_name = ft_strdup(
			parser->parser.ref.rule_name))
			? exit(EXIT_FAILURE) : 0;
	else if (parser->id == REGEXP)
		!(new_parser->parser.regexp.regexp = ft_strdup(
			parser->parser.regexp.regexp))
			? exit(EXIT_FAILURE) : 0;
	return (new_parser);
}

t_parser			*ft_assign_parsers(t_parser *parser, t_parser *new_parser)
{
	uint32_t	i;

	i = 0;
	if (!parser)
		return (new_parser);
	ft_memcpy(new_parser, parser, sizeof(t_parser));
	new_parser->alloc = GROUPED;
	if (parser->name)
		new_parser->name = ft_strdup(parser->name);
	if (parser->id >= FUNC)
		return (ft_assign_parser_data(parser, new_parser));
	else
		return (ft_assign_unary_parsers(parser, new_parser));
}
