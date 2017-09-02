/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser_misc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:13:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:15:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_free_parser_ref(t_parser *parser)
{
	free(parser->parser.ref.rule_name);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_func(t_parser *parser)
{
	ft_free_parser(parser->parser.func.parser);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_undefined(t_parser *parser)
{
	ft_putstr("feels bad man");
	(void)parser;
	ft_free_parser_struct(parser);
}
