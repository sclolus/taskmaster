/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_logical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:45:45 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 17:55:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint32_t		ft_eval_parser_or(t_parser *parser, char **string)
{
	uint32_t	ret;
	uint32_t	i;

	ret = 0;
	i = 0;
	while (!ret && i < parser->parser.or.n)
	{
		if (parser->parser.or.parsers[i]->id == STR_ANY)
			parser->parser.or.parsers[i]->parser.str_any.end = i + 1
				< parser->parser.or.n ? parser->parser.or.parsers[i + i]
				: NULL;
		ret |= ft_eval_parser(parser->parser.or.parsers[i], string);
		i++;
	}
	if (ret)
		parser->parser.or.matched = i - 1;
	return (ret);
}

uint32_t		ft_eval_parser_and(t_parser *parser, char **string)
{
	uint32_t	ret;
	uint32_t	i;

	ret = 1;
	i = 0;
	while (ret && i < parser->parser.and.n)
	{
		if (parser->parser.and.parsers[i]->id == STR_ANY)
			parser->parser.and.parsers[i]->parser.str_any.end = i + 1
				< parser->parser.and.n
				? parser->parser.and.parsers[i + i]
				: NULL;
		ret &= ft_eval_parser(parser->parser.and.parsers[i], string);
		i++;
	}
	return (ret);
}

uint32_t		ft_eval_parser_not(t_parser *parser, char **string)
{
	return (!ft_eval_parser(parser, string));
}

uint32_t		ft_eval_parser_undefined(t_parser *parser, char **string)
{
	if (parser)
		;
	ft_putstr_fd("error: undefined parser\n", 2);
	ft_putstr_fd("current string: ", 2);
	ft_putstr_fd(*string, 2);
	exit(EXIT_FAILURE);
}
