/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer_logicals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:05:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:06:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_sanitize_parser_not(t_parser *parser)
{
	parser->retained = 0;
	ft_sanitize_parser(parser->parser.not.parser);
}

void	ft_sanitize_parser_and_n(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	parser->retained = 0;
	while (i < parser->parser.and.n)
	{
		ft_sanitize_parser(parser->parser.and.parsers[i]);
		i++;
	}
}

void	ft_sanitize_parser_or_n(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	parser->retained = 0;
	parser->parser.or.matched = -1;
	while (i < parser->parser.or.n)
	{
		ft_sanitize_parser(parser->parser.or.parsers[i]);
		i++;
	}
}

void	ft_sanitize_parser_plus(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	parser->retained = 0;
	while (i < parser->parser.plus.n)
	{
		ft_free_parser(parser->parser.plus.parsers[i]);
		i++;
	}
	if (parser->parser.multiply.n)
		free(parser->parser.plus.parsers);
	parser->parser.plus.parsers = NULL;
	parser->parser.plus.n = 0;
}

void	ft_sanitize_parser_multiply(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	parser->retained = 0;
	while (i < parser->parser.multiply.n)
	{
		ft_free_parser(parser->parser.multiply.parsers[i]);
		i++;
	}
	if (parser->parser.multiply.n)
		free(parser->parser.plus.parsers);
	parser->parser.multiply.parsers = NULL;
	parser->parser.multiply.n = 0;
}
