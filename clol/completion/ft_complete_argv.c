/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:51:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/14 04:12:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_completion.h"

static int32_t	ft_is_shell_reserved(t_string *buf, uint32_t i)
{
	if (ft_strchr("|&;<>()$`\"' \t\n", buf->string[i])
		&& !ft_is_quoted(buf->string, i))
		return (1);
	return (0);
}

static char		*ft_get_current_token(t_string *buf)
{
	char		*token;
	uint32_t	i;
	uint32_t	start;

	if (buf->offset > 0)
		i = buf->offset - 1;
	start = 0;
	while (buf->offset)
	{
		if (ft_is_shell_reserved(buf, i))
		{
			start = i + 1;
			break ;
		}
		else if (i == 0)
			break ;
		i--;
	}
	if (!(token = ft_strndup(buf->string + start, buf->offset - start)))
		exit(EXIT_FAILURE);
	return (token);
}

void			ft_put_completions_tab(char **tab)
{
	while (*tab)
		ft_putendl(*tab++);
}

int32_t			ft_complete_argv(t_string *buf, t_shenv *shenv)
{
	char		**completions;
	char		*command_prefix;
	uint32_t	ret;

	command_prefix = ft_get_current_token(buf);
	(void)shenv;
	if (!(completions = ft_get_completions_tab(command_prefix)))
	{
		free(command_prefix);
		ft_putchar(7);
		return (0);
	}
	ret = ft_put_completion(completions, buf, command_prefix);
	ft_free_completion_tab(completions);
	free(command_prefix);
	return (ret);
}

int32_t			ft_completion_normal_state(t_string *buf, t_shenv *shenv)
{
	if (buf && shenv)
		;
	ft_putchar(7);
	return (0);
}
