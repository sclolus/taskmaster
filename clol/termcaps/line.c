/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:53:21 by aalves            #+#    #+#             */
/*   Updated: 2017/04/28 10:44:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void		ft_move_start_line(t_string *buf)
{
	while (buf->offset > 0)
		ft_move_left_cursor(buf);
}

void		ft_move_end_line(t_string *buf)
{
	while (buf->offset < buf->len)
		ft_move_right_cursor(buf);
}

void		ft_erase_line(void)
{
	char	*res;

	res = tgetstr("dl", NULL);
	tputs(res, 1, &ft_putterm);
}

int32_t		ft_kill_line(t_string *buf, t_list **paste_history)
{
	char			*res;
	static t_list	*paste_base = NULL;
	t_list			*tmp;

	if (!paste_base)
		paste_base = *paste_history;
	res = tgetstr("cd", NULL);
	tputs(res, 1, &ft_putterm);
	if (!(tmp = ft_lstnew(buf->string + buf->offset,
				ft_strlen(buf->string + buf->offset) + 1)))
		exit(EXIT_FAILURE);
	ft_lstadd(paste_history, tmp);
	if (paste_base)
	{
		tmp->prev = paste_base;
		tmp->next->prev = tmp;
		paste_base->next = tmp;
	}
	buf->string[buf->offset] = '\0';
	buf->len = buf->offset;
	return (1);
}
