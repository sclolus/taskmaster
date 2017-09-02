/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_misc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:46:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 18:04:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint32_t		ft_eval_parser_invocations(t_parser *parser, char **string)
{
	uint32_t	i;

	i = 0;
	while (i < 3)
	{
		if (!ft_eval_parser(parser->parser.and.parsers[i], string))
			return (0);
		i++;
	}
	parser->parser.and.parsers[i] = ft_get_parser_expression();
	while (i < 8)
	{
		if (!(ft_eval_parser(parser->parser.and.parsers[i], string)))
			return (0);
		i++;
	}
	return (1);
}

uint32_t		ft_eval_delayed(t_parser *parser, char **string)
{
	return (ft_eval_parser(parser, string));
}

uint32_t		ft_eval_parser_func(t_parser *parser, char **string)
{
	parser->parser.func.parser = parser->parser.func.gene();
	return (parser->parser.func.f(parser->parser.func.parser, string));
}
