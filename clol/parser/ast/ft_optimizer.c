/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:38:43 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:08:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint32_t	ft_is_case_str_any_of(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	if (parser->id != OR)
		return (0);
	while (i < parser->parser.or.n)
	{
		if (parser->parser.or.parsers[i]->id != ONECHAR)
			return (0);
		i++;
	}
	return (1);
}

void		ft_optimize_case_str_any_of(t_parser *parser)
{
	char		*charset;
	uint32_t	i;
	uint32_t	n;

	i = 0;
	n = parser->parser.plus.parser->parser.or.n;
	if (!(charset = ft_strnew(n)))
		exit(EXIT_FAILURE);
	while (i < n)
	{
		charset[i] = parser->parser.plus.parser->parser.or.parsers[i]
			->parser.onechar.c;
		i++;
	}
	ft_free_parser(parser->parser.plus.parser);
	parser->id = STR_ANY_OF;
	parser->retained = UNRETAINED;
	parser->parser.str_any_of.charset = charset;
	parser->parser.str_any_of.str = NULL;
}

void		ft_optimizer(t_parser *parser)
{
	uint32_t	i;

	i = 0;
	if (parser->id == OR || parser->id == AND)
	{
		while (i < parser->parser.or.n)
		{
			ft_optimizer(parser->parser.or.parsers[i]);
			i++;
		}
	}
	else if (parser->id == PLUS)
	{
		if (ft_is_case_str_any_of(parser->parser.plus.parser))
			ft_optimize_case_str_any_of(parser);
		else
			ft_optimizer(parser->parser.plus.parser);
	}
	else if (parser->id == MULTIPLY)
		ft_optimizer(parser->parser.plus.parser);
	else if (parser->id == FUNC)
		ft_optimizer(parser->parser.func.parser);
}
