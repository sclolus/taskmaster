/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_completion_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:23:47 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/15 10:03:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_new_completion.h"

void	ft_free_completion_tab(char **tab)
{
	uint32_t	i;

	if (!(tab))
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_completions_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		free(lst->content);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
