/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:53:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/09 03:37:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_clear_heredoc(t_list *heredoc)
{
	free(((t_heredoc*)heredoc->content)->filename);
	free(((t_heredoc*)heredoc->content)->delimiter);
	if (heredoc->next)
		heredoc->next->prev = NULL;
	free(heredoc->content);
	free(heredoc);
}

void		ft_clear_heredocs(t_shenv *shenv)
{
	while (shenv->heredocs)
		ft_delone_heredoc(shenv);
}

void		ft_delone_heredoc(t_shenv *shenv)
{
	t_list	*tmp;

	if (shenv->heredocs->next)
		tmp = shenv->heredocs->next;
	else
		tmp = NULL;
	ft_clear_heredoc(shenv->heredocs);
	shenv->heredocs = tmp;
}
