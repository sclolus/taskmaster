/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser_strings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:13:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:15:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_free_parser_satisfy_str(t_parser *parser)
{
	ft_free_parser_struct(parser);
}

void	ft_free_parser_str_any_of(t_parser *parser)
{
	free(parser->parser.str_any_of.charset);
	if (parser->parser.str_any_of.str)
		free(parser->parser.str_any_of.str);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_str_any(t_parser *parser)
{
	if (parser->parser.str_any.str)
		free(parser->parser.str_any.str);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_str(t_parser *parser)
{
	free(parser->parser.string.str);
	ft_free_parser_struct(parser);
}

void	ft_free_parser_regexp(t_parser *parser)
{
	free(parser->parser.regexp.regexp);
	ft_free_parser_struct(parser);
}
