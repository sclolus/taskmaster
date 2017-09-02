/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer_strings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:04:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:05:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_sanitize_parser_str_any_of(t_parser *parser)
{
	parser->retained = 0;
	free(parser->parser.str_any_of.str);
	parser->parser.str_any_of.str = NULL;
}

void	ft_sanitize_parser_str_any(t_parser *parser)
{
	parser->retained = 0;
	free(parser->parser.str_any.str);
	parser->parser.str_any.str = NULL;
}

void	ft_sanitize_parser_str(t_parser *parser)
{
	parser->retained = 0;
	parser->parser.string.len = 0;
	parser->parser.string.str = NULL;
}

void	ft_sanitize_parser_regexp(t_parser *parser)
{
	parser->retained = 0;
}

void	ft_sanitize_parser_satisfy_str(t_parser *parser)
{
	parser->retained = 0;
}
