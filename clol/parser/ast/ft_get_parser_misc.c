/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parser_misc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:26:38 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 18:26:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_parser_func(t_parser *(*generator)(void)
								, uint32_t (*f)(t_parser*, char **))
{
	t_parser	*new_parser;

	new_parser = ft_get_undefined_parser();
	new_parser->id = FUNC;
	new_parser->parser.func.parser = NULL;
	new_parser->parser.func.f = f;
	new_parser->parser.func.gene = generator;
	return (new_parser);
}

t_parser	*ft_get_parser_ref(char *rule_name)
{
	t_parser	*parser;

	parser = ft_get_undefined_parser();
	parser->id = REF;
	if (!(parser->parser.ref.rule_name = ft_strdup(rule_name)))
		exit(EXIT_FAILURE);
	return (parser);
}

void		ft_set_name_parser(t_parser *parser, char *str)
{
	if (!(parser->name = ft_strdup(str)))
		exit(EXIT_FAILURE);
}
