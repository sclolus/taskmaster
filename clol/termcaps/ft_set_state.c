/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 08:16:44 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/08 16:49:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

t_termcaps_state	*ft_get_term_state(void)
{
	static t_termcaps_state	state = NORMAL;

	return (&state);
}

void				ft_put_term_state(t_termcaps_state *state)
{
	ft_putchar('\n');
	if (*state == NORMAL)
		ft_putendl("NORMAL");
	else if (*state == COMMAND_NAME)
		ft_putendl("COMMAND_NAME");
	else if (*state == ARGV)
		ft_putendl("ARGV");
}

static void			ft_choose_state(int32_t command_pos,
				int8_t bool, t_termcaps_state *state)
{
	if (command_pos == 1 && bool)
		*state = COMMAND_NAME;
	else if (command_pos > 1 && bool)
		*state = ARGV;
	else
		*state = NORMAL;
}

static void			ft_set_term_state_setup(uint32_t *i, int32_t *command_pos
											, int8_t *bool)
{
	*bool = 0;
	*i = 0;
	*command_pos = 0;
}

void				ft_set_term_state(t_string *buf)
{
	uint32_t			i;
	int32_t				command_pos;
	int8_t				bool;

	ft_set_term_state_setup(&i, &command_pos, &bool);
	while (i < buf->offset)
	{
		while (i < buf->offset && ft_strchr(" \t\n", buf->string[i])
			&& !ft_is_quoted(buf->string, i) && ++i)
			bool = 0;
		if (i == buf->offset)
			break ;
		if (ft_strchr("&;|", buf->string[i])
			&& !ft_is_quoted(buf->string, i) && !(bool = 0))
			command_pos = 0;
		else if (!bool && (!ft_strchr(" \t\n", buf->string[i])
						|| ft_is_quoted(buf->string, i)) && (bool = 1))
			command_pos++;
		else if (bool && ft_strchr(" \t\n", buf->string[i])
			&& !ft_is_quoted(buf->string, i))
			bool = 0;
		i++;
	}
	ft_choose_state(command_pos, bool, ft_get_term_state());
}
