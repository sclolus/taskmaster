/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grammar_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:18:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 16:33:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_get_grammar_syntax(t_parser *syntax)
{
	t_parser	*parser;
	t_parser	**parsers;
	uint32_t	i;

	i = 0;
	if (!(parsers = (t_parser**)malloc((syntax->parser.plus.n + 1)
									* sizeof(t_parser*))))
		exit(EXIT_FAILURE);
	while (i < syntax->parser.plus.n)
	{
		parsers[i] = ft_get_grammar_rule(syntax->parser.plus.parsers[i]);
		i++;
	}
	parsers[i] = NULL;
	i = 0;
	ft_link_rule_name(parsers, &parsers[0]);
	i = 1;
	parser = parsers[0];
	while (parsers[i])
		ft_free_parser(parsers[i++]);
	free(parsers);
	return (parser);
}
