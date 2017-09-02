/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:46:41 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/05 23:04:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_add_token_to_list(t_list **token_list
									, char *input, uint32_t start, uint32_t i)
{
	t_list	*tmp;
	char	*tmp_token;

	if (!(tmp = ft_lstnew(0, 0)))
		exit(EXIT_FAILURE);
	if (!(tmp_token = ft_strsub(input, start, i - start)))
		exit(EXIT_FAILURE);
	tmp->content = tmp_token;
	ft_lstadd(token_list, tmp);
}

char			**ft_token_list_to_tab(t_list *token_list)
{
	char		**tab;
	t_list		*tmp;
	uint32_t	i;
	uint32_t	size;

	size = ft_lstlen(token_list);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		tab[size - i - 1] = token_list->content;
		tmp = token_list;
		token_list = token_list->next;
		free(tmp);
		i++;
	}
	return (tab);
}
