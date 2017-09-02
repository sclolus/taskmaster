/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 10:43:47 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/28 12:03:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static void	ft_assign_lists(t_list **static_history, t_list **history_base
							, t_list **current_yanking, t_list *paste_history)
{
	if (*history_base != paste_history)
	{
		*history_base = paste_history;
		*static_history = paste_history;
		*current_yanking = paste_history;
	}
}

int32_t		ft_paste_line(t_string *buf, char *command, t_list *paste_history)
{
	char			*tmp;
	static t_list	*static_history = NULL;
	static t_list	*history_base = NULL;
	static t_list	*toto = NULL;

	tmp = NULL;
	ft_assign_lists(&static_history, &history_base
					, &toto, paste_history);
	if (history_base == NULL)
		return (1);
	else if (*command == ID_YANKING)
	{
		if (!toto->content)
			return (1);
		tmp = toto->content;
	}
	else if (*(int*)command == ID_HISTORIC_YANKING)
	{
		if (!static_history->content)
			return (1);
		ft_explore_paste_history(buf, &static_history, &history_base, &toto);
	}
	ft_t_string_insert(buf, tmp);
	ft_termcaps_putstr(buf, tmp);
	return (1);
}
