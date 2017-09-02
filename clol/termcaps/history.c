/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:19:35 by aalves            #+#    #+#             */
/*   Updated: 2017/04/28 10:36:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

t_list		**ft_get_history_list(void)
{
	static t_list	*history_list = NULL;

	return (&history_list);
}

void		ft_get_history(t_list *history, char *command, t_string *buf)
{
	char			*tmp;
	static t_list	*static_history = NULL;
	static t_list	*history_base = NULL;

	if (history_base != history)
	{
		history_base = history;
		static_history = history;
	}
	tmp = NULL;
	if (history_base == NULL)
		return ;
	if (static_history->content)
	{
		tmp = static_history->content;
		if (command[2] == 66)
			static_history = static_history->prev
			? static_history->prev : history_base;
		else
			static_history = static_history->next
			? static_history->next : history_base;
	}
	ft_print_history(buf, tmp);
}

void		ft_print_history(t_string *buf, char *history)
{
	uint32_t	len;

	len = 0;
	ft_move_end_line(buf);
	while (buf->offset > 0)
		ft_delete_char(buf);
	*buf->string = '\0';
	buf->len = 0;
	if ((len = ft_strlen(history)))
	{
		ft_t_string_concat(buf, history);
		write(1, history, len);
	}
}

void		ft_explore_paste_history(t_string *buf, t_list **static_history,
				t_list **history_base, t_list **current_yanking)
{
	char			*tmp;
	uint64_t		i;

	i = 0;
	tmp = (*static_history)->content;
	i = ft_strlen((*static_history)->prev ? (*static_history)->prev->content
			: (*static_history)->content);
	*current_yanking = (*static_history);
	while (i--)
		ft_delete_char(buf);
	(*static_history) = (*static_history)->next ? (*static_history)->next
	: *history_base;
}
