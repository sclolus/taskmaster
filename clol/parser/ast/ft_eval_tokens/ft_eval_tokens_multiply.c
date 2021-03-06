/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_tokens_multiply.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:33:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 20:37:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void		ft_get_multiply_parser(t_parser *parser, uint32_t n
									, t_list *head)
{
	t_list		*link;
	uint32_t	i;

	parser->parser.multiply.n = n;
	if (!(parser->parser.multiply.parsers = (t_parser**)malloc(n
											* sizeof(t_parser*))))
		exit(EXIT_FAILURE);
	i = n - 1;
	while (head)
	{
		parser->parser.multiply.parsers[i] = head->content;
		link = head;
		head = head->next;
		free(link);
		--i;
	}
}

uint32_t		ft_eval_tokens_multiply(t_parser *parser, t_tokens *tokens)
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
		link->content = ft_dup_parser(parser->parser.multiply.parser);
		if (!ft_eval_tokens(link->content, tokens))
		{
			ft_free_parser(link->content);
			free(link);
			break ;
		}
		ft_lstadd(&head, link);
		++n;
	}
	if (n)
		ft_get_multiply_parser(parser, n, head);
	return (1);
}
