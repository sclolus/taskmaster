/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_strings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:44:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:28:35 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint32_t		ft_eval_parser_satisfy_str(t_parser *parser, char **string)
{
	uint32_t	ret;

	if ((ret = parser->parser.satisfy_str.f(*string)))
	{
		(*string) += ret;
		return (1);
	}
	else
		return (0);
}

uint32_t		ft_eval_parser_str(t_parser *parser, char **string)
{
	if (!(ft_memcmp(parser->parser.string.str
					, *string, parser->parser.string.len)))
	{
		*string += parser->parser.string.len;
		return (1);
	}
	else
		return (0);
}

uint32_t		ft_eval_parser_str_any(t_parser *parser, char **string)
{
	uint32_t	ret;
	uint32_t	c;

	ret = 0;
	c = 0;
	if (parser->parser.str_any.end)
	{
		parser->parser.str_any.str = *string;
		while (**string
			&& !(ret = (ft_eval_parser(parser->parser.str_any.end, string))))
		{
			(*string)++;
			c++;
		}
		ret ? (*string)-- : 0;
		parser->parser.str_any.len = c;
		parser->parser.str_any.str = ft_strndup(parser->parser.str_any.str, c);
	}
	else
	{
		parser->parser.str_any.str = *string;
		parser->parser.str_any.len = ft_strlen(*string);
		(*string) += parser->parser.str_any.len;
	}
	return (1);
}
