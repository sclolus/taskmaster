/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:49:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:15:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_free_parser_struct(t_parser *parser)
{
	if (!parser)
		return ;
	if (parser->name)
		free(parser->name);
	if (parser->alloc == ALONE)
		free(parser);
}

void	ft_free_parser(t_parser *parser)
{
	static const t_free_parser	free_parsers[18] = {
		{ft_free_parser_undefined},
		{ft_free_parser_ref},
		{ft_free_parser_onechar},
		{ft_free_parser_str},
		{ft_free_parser_regexp},
		{ft_free_parser_char_range},
		{ft_free_parser_any},
		{ft_free_parser_str_any_of},
		{ft_free_parser_satisfy},
		{ft_free_parser_satisfy_str},
		{ft_free_parser_str_any},
		{ft_free_parser_oneof},
		{ft_free_parser_func},
		{ft_free_parser_and_n},
		{ft_free_parser_or_n},
		{ft_free_parser_not},
		{ft_free_parser_plus},
		{ft_free_parser_multiply}};

	if (!parser)
		return ;
	free_parsers[parser->id].f(parser);
}
