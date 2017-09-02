/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grammar_linker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:33:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 16:33:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_parser	*ft_find_rule_name(t_parser **ruleset, char *name)
{
	uint32_t			i;

	i = 0;
	while (ruleset[i])
	{
		if (!ft_strcmp(ruleset[i]->name, name))
			return (ruleset[i]);
		++i;
	}
	ft_putstr_fd(name, 2);
	ft_putstr_fd("not found", 2);
	exit(EXIT_FAILURE);
}

void		ft_link_rule_name(t_parser **ruleset, t_parser **node)
{
	t_parser	*parser;
	uint32_t	i;

	i = 0;
	if ((*node)->id == REF)
	{
		parser = ft_find_rule_name(ruleset, (*node)->parser.ref.rule_name);
		free((*node)->parser.ref.rule_name);
		if ((*node)->alloc == ALONE)
			free(*(node));
		*(node) = ft_dup_parser(parser);
		ft_link_rule_name(ruleset, node);
	}
	if ((*node)->id >= AND)
	{
		if ((*node)->id == AND || (*node)->id == OR)
		{
			while (i < (*node)->parser.and.n)
				ft_link_rule_name(ruleset, &((*node)->parser.and.parsers[i++]));
		}
		else
			ft_link_rule_name(ruleset, &((*node)->parser.not.parser));
	}
	else
		return ;
}

t_parser	*ft_get_grammar_or_n(uint32_t n
								, t_parser *first, t_parser **parsers)
{
	t_parser	*parser;
	uint32_t	i;

	i = 0;
	parser = ft_get_undefined_parser();
	parser->id = OR;
	parser->parser.or.matched = -1;
	if (!(parser->parser.or.parsers = (t_parser**)malloc(sizeof(t_parser*)
													* n)))
		exit(EXIT_FAILURE);
	parser->parser.or.n = n;
	parser->parser.or.parsers[0] = ft_get_grammar_list(first);
	while (i + 1 < n)
	{
		parser->parser.or.parsers[i + 1] = ft_get_grammar_list(
			parsers[i]->parser.and.parsers[3]);
		i++;
	}
	return (parser);
}
