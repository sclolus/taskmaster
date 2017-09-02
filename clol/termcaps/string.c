/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 02:07:08 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/07 04:56:35 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			ft_putterm(int c)
{
	return (write(1, &c, 1));
}

void		ft_delete_char(t_string *buf)
{
	char	*res;

	if (buf->offset > 0)
	{
		ft_move_left_cursor(buf);
		ft_strcpy(buf->string + buf->offset, buf->string + buf->offset + 1);
		buf->len--;
		res = tgetstr("dc", NULL);
		tputs(res, 1, &ft_putterm);
		ft_termcaps_putstr(buf, NULL);
	}
}

t_string	*ft_t_string_concat(t_string *string, char *str)
{
	uint64_t	total_len;
	uint64_t	str_len;

	if (!str || !string)
		return (NULL);
	str_len = ft_strlen(str);
	total_len = string->len + str_len;
	if (total_len >= string->capacity)
	{
		ft_t_string_expand(string);
		return (ft_t_string_concat(string, str));
	}
	else
	{
		ft_strcat(string->string, str);
		string->len = total_len;
		string->offset = total_len;
	}
	return (string);
}

t_string	*ft_t_string_insert(t_string *string, char *str)
{
	uint64_t	total_len;
	uint64_t	str_len;

	if (!str || !string)
		return (NULL);
	str_len = ft_strlen(str);
	total_len = string->len + str_len;
	if (total_len >= string->capacity)
		ft_t_string_expand(string);
	ft_memmove(string->string + string->offset + str_len,
				string->string + string->offset,
				string->len - string->offset);
	ft_memcpy(string->string + string->offset, str, str_len);
	string->len += str_len;
	string->offset += str_len;
	string->string[string->len] = 0;
	return (string);
}

void		ft_t_string_expand(t_string *string)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = ft_strnew(string->capacity * 2)))
		exit(EXIT_FAILURE);
	string->capacity *= 2;
	ft_strcpy(tmp, string->string);
	free(string->string);
	string->string = tmp;
}
