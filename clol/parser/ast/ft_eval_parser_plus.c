/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:46:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 17:58:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void		ft_get_plus_parsers(t_parser *parser, uint32_t n
										, t_list *head)
{
	uint32_t	i;
	t_list		*link;

	parser->parser.plus.n = n;
	if (!(parser->parser.plus.parsers = (t_parser**)malloc(n
										* sizeof(t_parser*))))
		exit(EXIT_FAILURE);
	i = n - 1;
	while (head)
	{
		parser->parser.plus.parsers[i] = head->content;
		link = head;
		head = head->next;
		free(link);
		--i;
	}
}

uint32_t		ft_eval_parser_plus(t_parser *parser, char **string)
{
	t_list		*head;
	t_list		*link;
	uint32_t	n;

	n = 0;
	head = NULL;
	while (1)
	{
		if (!(link = ft_lstnew(NULL, sizeof(t_parser*))))
			exit(EXIT_FAILURE);
		link->content = ft_dup_parser(parser->parser.plus.parser);
		if (!ft_eval_parser(link->content, string))
		{
			ft_free_parser(link->content);
			free(link);
			break ;
		}
		ft_lstadd(&head, link);
		++n;
	}
	if (n)
		ft_get_plus_parsers(parser, n, head);
	return (n != 0);
}
