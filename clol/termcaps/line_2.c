/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 20:47:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/09 06:34:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	ft_move_prev_word(t_string *buf)
{
	t_bool	in_word;

	if (buf->offset == 0)
	{
		ft_putchar(7);
		return ;
	}
	if (ft_isalnum(buf->string[buf->offset - 1]))
		in_word = 1;
	else
		in_word = 0;
	while (buf->offset - 1 >= 0)
	{
		if (!ft_isalnum(buf->string[buf->offset - 1]) && in_word)
			break ;
		else if (ft_isalnum(buf->string[buf->offset - 1]))
			in_word = 1;
		else
			in_word = 0;
		ft_move_left_cursor(buf);
	}
}

void	ft_move_next_word(t_string *buf)
{
	t_bool	in_word;

	if (buf->offset == buf->len)
	{
		ft_putchar(7);
		return ;
	}
	if (ft_isalnum(buf->string[buf->offset]))
		in_word = 1;
	else
		in_word = 0;
	while (buf->offset < buf->len)
	{
		if ((ft_isalnum(buf->string[buf->offset]) && !in_word)
			|| (in_word && !ft_isalnum(buf->string[buf->offset])))
			break ;
		else if (ft_isalnum(buf->string[buf->offset]))
			in_word = 1;
		else
			in_word = 0;
		ft_move_right_cursor(buf);
	}
}

void	ft_termcaps_putstr(t_string *buf, char *str)
{
	char					*res;
	int64_t					old_offset;

	old_offset = buf->offset;
	if (str)
		buf->offset -= ft_strlen(str);
	ft_move_start_line(buf);
	res = tgetstr("cr", NULL);
	tputs(res, 1, &ft_putterm);
	tputs(res, 1, &ft_putterm);
	res = tgetstr("cd", NULL);
	ft_put_prompt();
	tputs(res, 1, &ft_putterm);
	write(1, buf->string, buf->len);
	buf->offset += buf->len;
	while (buf->offset > old_offset)
		ft_move_left_cursor(buf);
}
