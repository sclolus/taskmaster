/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parser_chars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:15:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 18:42:35 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_parser_onechar(char c)
{
	t_parser	*parser;

	parser = ft_get_undefined_parser();
	parser->parser.onechar.c = c;
	parser->id = ONECHAR;
	return (parser);
}

t_parser	*ft_get_parser_range(char start, char end)
{
	t_parser	*parser;

	parser = ft_get_undefined_parser();
	parser->id = RANGE;
	parser->parser.range.start = start;
	parser->parser.range.end = end;
	return (parser);
}

t_parser	*ft_get_parser_any(void)
{
	t_parser	*parser;

	parser = ft_get_undefined_parser();
	parser->id = ANY;
	return (parser);
}

t_parser	*ft_get_parser_satisfy(int32_t f(char))
{
	t_parser	*parser;

	parser = ft_get_undefined_parser();
	parser->id = SATISFY;
	parser->parser.satisfy.f = f;
	return (parser);
}

t_parser	*ft_get_parser_oneof(char *charset)
{
	t_parser	*parser;

	parser = ft_get_undefined_parser();
	parser->id = ONEOF;
	if (!(parser->parser.oneof.charset = ft_strdup(charset)))
		exit(EXIT_FAILURE);
	parser->parser.oneof.c = 0;
	return (parser);
}
