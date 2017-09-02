/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer_misc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:06:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:06:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_sanitize_parser_ref(t_parser *parser)
{
	parser->retained = 0;
}

void	ft_sanitize_parser_func(t_parser *parser)
{
	parser->retained = 0;
	ft_sanitize_parser(parser->parser.func.parser);
}

void	ft_sanitize_parser_undefined(t_parser *parser)
{
	parser->retained = 0;
	ft_putstr_fd("Sanitizing undefined parser", 2);
}
