/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termget_buf_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:45:54 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/13 19:25:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_termget_buf_setup(t_string *buf)
{
	buf->len = 0;
	buf->offset = 0;
	if (buf->string == NULL)
		if (!(buf->string = ft_strnew(255)))
			exit(EXIT_FAILURE);
	*(buf->string) = 0;
}

void		ft_buf_update(t_string *buf, char *tmp)
{
	if (ft_isprint(*tmp))
	{
		tmp[1] = 0;
		if (buf->offset == buf->len)
		{
			ft_putchar(*tmp);
			ft_t_string_concat(buf, tmp);
		}
		else
		{
			ft_t_string_insert(buf, tmp);
			ft_termcaps_putstr(buf, tmp);
		}
	}
}

uint32_t	ft_termget_cleanup(char *tmp, t_string *buf, char **line)
{
	ft_putchar('\n');
	*line = buf->string;
	if (*(long*)tmp == 4)
		return (-1);
	if (*(long*)tmp == 3)
	{
		*line = tmp + 7;
		return (-1);
	}
	return (buf->len);
}
