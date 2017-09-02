/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser_logicals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:12:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:15:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_free_parser_and_n(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	while (i < parser->parser.and.n)
	{
		ft_free_parser(parser->parser.and.parsers[i]);
		i++;
	}
	free(parser->parser.and.parsers);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_or_n(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	while (i < parser->parser.or.n)
	{
		ft_free_parser(parser->parser.or.parsers[i]);
		i++;
	}
	free(parser->parser.or.parsers);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_plus(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	while (i < parser->parser.plus.n)
	{
		ft_free_parser(parser->parser.plus.parsers[i]);
		i++;
	}
	if (parser->parser.plus.n)
		free(parser->parser.plus.parsers);
	ft_free_parser(parser->parser.plus.parser);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_multiply(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	while (i < parser->parser.multiply.n)
	{
		ft_free_parser(parser->parser.multiply.parsers[i]);
		i++;
	}
	if (parser->parser.plus.n)
		free(parser->parser.multiply.parsers);
	ft_free_parser(parser->parser.multiply.parser);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_not(t_parser *parser)
{
	free(parser->parser.not.parser);
	ft_free_parser_struct(parser);
}
