/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:35:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 21:24:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static uint32_t		ft_count_parsers(t_parser *parser)
{
	uint32_t	i;
	uint32_t	count;

	i = 0;
	count = 0;
	if (parser == NULL)
		return (1);
	if (parser->id >= FUNC)
	{
		if (parser->id == FUNC)
			return (1);
		else if (parser->id == AND || parser->id == OR)
		{
			while (i < parser->parser.and.n)
			{
				count += ft_count_parsers(parser->parser.and.parsers[i]);
				i++;
			}
			return (count + 1);
		}
		else
			return (ft_count_parsers(parser->parser.not.parser) + 1);
	}
	else
		return (1);
}

t_parser			*ft_dup_parser(t_parser *parser)
{
	t_parser	*new_parser;
	uint32_t	size;

	size = ft_count_parsers(parser);
	if (!(new_parser = (t_parser*)malloc(size * sizeof(t_parser))))
		exit(EXIT_FAILURE);
	ft_assign_parsers(parser, new_parser);
	new_parser->alloc = ALONE;
	return (new_parser);
}
