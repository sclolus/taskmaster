/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:03:38 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:04:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_sanitize_parser_onechar(t_parser *parser)
{
	parser->retained = 0;
}

void	ft_sanitize_parser_any(t_parser *parser)
{
	parser->retained = 0;
	parser->parser.any.matched = 0;
}

void	ft_sanitize_parser_char_range(t_parser *parser)
{
	parser->retained = 0;
	parser->parser.range.matched = 0;
}

void	ft_sanitize_parser_satisfy(t_parser *parser)
{
	parser->retained = 0;
}

void	ft_sanitize_parser_oneof(t_parser *parser)
{
	parser->retained = 0;
	parser->parser.oneof.c = 0;
}
