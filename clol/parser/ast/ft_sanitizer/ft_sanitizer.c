/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:02:14 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:06:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_sanitize_parser(t_parser *parser)
{
	static const t_free_parser	sanitize_parsers[18] = {
		{ft_sanitize_parser_undefined},
		{ft_sanitize_parser_ref},
		{ft_sanitize_parser_onechar},
		{ft_sanitize_parser_str},
		{ft_sanitize_parser_regexp},
		{ft_sanitize_parser_char_range},
		{ft_sanitize_parser_any},
		{ft_sanitize_parser_str_any_of},
		{ft_sanitize_parser_satisfy},
		{ft_sanitize_parser_satisfy_str},
		{ft_sanitize_parser_str_any},
		{ft_sanitize_parser_oneof},
		{ft_sanitize_parser_func},
		{ft_sanitize_parser_and_n},
		{ft_sanitize_parser_or_n},
		{ft_sanitize_parser_not},
		{ft_sanitize_parser_plus},
		{ft_sanitize_parser_multiply}};

	if (!parser)
		return ;
	sanitize_parsers[parser->id].f(parser);
}
