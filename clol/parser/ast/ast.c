/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:05:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 19:00:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int32_t		ft_is_metachar(char c)
{
	if (ft_strchr(MPC_PARSING_METACHAR, c))
		return (1);
	else
		return (0);
}

int32_t		ft_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

t_parser	*ft_get_parser_whitespace(void)
{
	t_parser	*parser;

	parser = ft_get_parser_multiply(ft_get_parser_or_n(2,
							(t_parser *[]){ft_get_parser_onechar(' '),
								ft_get_parser_onechar('\t')}));
	ft_set_name_parser(parser, "<whitespace>");
	return (parser);
}
