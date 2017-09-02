/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:48:47 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/14 06:37:57 by sclolus          ###   ########.fr       */
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

int32_t			ft_complete_path_commands(t_string *buf, t_shenv *shenv,
											char *command_prefix)
{
	char		**completions;
	char		**path;
	char		*pathname;
	uint32_t	i;
	int32_t		ret;

	pathname = ft_get_path_name(command_prefix);
	if (!pathname || *pathname)
		return (0);
	(i = 0) ? 0 : ft_free_t_env(shenv->env);
	shenv->env = ft_get_env(shenv);
	if (!(path = ft_get_env_value(shenv->env->env, "PATH")))
		return (0);
	if (!(completions = ft_get_command_bin_completions_tab(command_prefix,
																	path)))
	{
		ft_free_argv(path);
		return (0);
	}
	ret = ft_put_completion(completions, buf, command_prefix);
	ft_free_argv(path);
	ft_free_completion_tab(completions);
	return (ret);
}

int32_t			ft_complete_command_directory(t_string *buf, t_shenv *shenv,
												char *command_prefix)
{
	char		**completions;
	char		*path;
	uint32_t	ret;

	(void)shenv;
	if (!(path = ft_get_path_name(command_prefix)))
		return (0);
	if (!(completions =
		ft_get_command_directory_completions_tab(command_prefix)))
		return (0);
	ret = ft_put_completion(completions, buf, command_prefix);
	ft_free_completion_tab(completions);
	return (ret);
}

int32_t			ft_complete_command_name(t_string *buf, t_shenv *shenv)
{
	char		*command_prefix;
	int32_t		ret;

	command_prefix = ft_get_current_token(buf);
	if ((ret = ft_complete_path_commands(buf, shenv, command_prefix)))
	{
		free(command_prefix);
		return (1);
	}
	else
	{
		ret = ft_complete_command_directory(buf, shenv, command_prefix);
		if (!ret)
			ft_putchar(7);
		free(command_prefix);
		return (ret);
	}
}
