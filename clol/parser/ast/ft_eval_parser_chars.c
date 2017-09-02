/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:43:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 16:44:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint32_t		ft_eval_parser_onechar(t_parser *parser, char **string)
{
	if (parser->parser.onechar.c == **string)
	{
		(*string)++;
		return (1);
	}
	else
		return (0);
}

uint32_t		ft_eval_parser_any(t_parser *parser, char **string)
{
	if (**string != '\0')
	{
		parser->parser.any.matched = **string;
		(*string)++;
		return (1);
	}
	else
		return (0);
}

uint32_t		ft_eval_parser_satisfy(t_parser *parser, char **string)
{
	if (parser->parser.satisfy.f(**string))
	{
		(*string)++;
		return (1);
	}
	else
		return (0);
}

uint32_t		ft_eval_parser_char_range(t_parser *parser, char **string)
{
	if (**string >= parser->parser.range.start
		&& **string <= parser->parser.range.end)
	{
		parser->parser.range.matched = **string;
		(*string)++;
		return (1);
	}
	else
		return (0);
}

uint32_t		ft_eval_parser_oneof(t_parser *parser, char **string)
{
	if (ft_strchr(parser->parser.oneof.charset, **string))
	{
		parser->parser.oneof.c = **string;
		(*string)++;
		return (1);
	}
	else
		return (0);
}
