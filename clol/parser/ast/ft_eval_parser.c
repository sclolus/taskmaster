/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 00:55:46 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 17:10:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint32_t		ft_eval_input_file(uint32_t fd, t_parser *parser)
{
	char		*string;
	char		*tmp;
	static char	buf[2048];
	int32_t		ret;

	ret = 0;
	if (!(string = ft_strnew(0)))
		exit(EXIT_FAILURE);
	while ((ret = read(fd, buf, 2047)) > 0)
	{
		buf[ret] = 0;
		if (!(string = ft_strjoin_f(string, buf, 0)))
			exit(EXIT_FAILURE);
	}
	tmp = string;
	ret = ft_eval_input(parser, &string);
	free(tmp);
	return (ret);
}

uint32_t		ft_eval_input(t_parser *parser, char **string)
{
	uint32_t	ret;

	if ((ret = ft_eval_parser(parser, string)) && !**string)
		return (1);
	return (0);
}

uint32_t		ft_eval_parser(t_parser *parser, char **string)
{
	char						*base;
	uint32_t					ret;
	static const t_eval_parser	eval_parsers[18] = {
		{&ft_eval_parser_undefined}, {&ft_eval_parser_undefined},
		{&ft_eval_parser_onechar}, {&ft_eval_parser_str},
		{&ft_eval_parser_undefined}, {&ft_eval_parser_char_range},
		{&ft_eval_parser_any}, {&ft_eval_parser_str_any_of},
		{&ft_eval_parser_satisfy}, {&ft_eval_parser_satisfy_str},
		{&ft_eval_parser_str_any}, {&ft_eval_parser_oneof},
		{&ft_eval_parser_func}, {&ft_eval_parser_and},
		{&ft_eval_parser_or}, {&ft_eval_parser_not},
		{&ft_eval_parser_plus}, {&ft_eval_parser_multiply}};

	base = *string;
	ret = eval_parsers[parser->id].f(parser, string);
	if (ret)
		parser->retained = RETAINED;
	else
	{
		parser->retained = UNRETAINED;
		*string = base;
	}
	return (ret);
}
