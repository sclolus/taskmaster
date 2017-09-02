/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_str_any_of.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:18:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:23:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static uint32_t	ft_t_string_buf_str_any_of(char **string, uint32_t offset
										, char *buf, t_string *str)
{
	if (offset < 4096)
	{
		buf[offset] = **string;
		(*string)++;
		return (offset + 1);
	}
	else
	{
		ft_t_string_concat_len(str, buf, 4096);
		return (0);
	}
}

uint32_t		ft_eval_parser_str_any_of(t_parser *parser, char **string)
{
	static char			buf[4096];
	t_string			*str;
	uint32_t			bool;
	uint32_t			offset;

	bool = 0;
	offset = 0;
	str = ft_t_string_new(32);
	while (**string)
	{
		if (ft_strchr(parser->parser.str_any_of.charset, **string))
		{
			bool |= 1;
			offset = ft_t_string_buf_str_any_of(string, offset, buf, str);
		}
		else
			break ;
	}
	if (offset)
		ft_t_string_concat_len(str, buf, offset);
	parser->parser.str_any_of.str = str->string;
	free(str);
	return (bool);
}
