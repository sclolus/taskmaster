/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_continuation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 06:13:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/28 12:15:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t	ft_is_unbalanced(char *line)
{
	int32_t		single_quotes;
	int32_t		double_quotes;
	uint32_t	i;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (line[i])
	{
		if (line[i] == '\'' && (!ft_is_escaped(line, i)
								|| single_quotes)
								&& !double_quotes)
			single_quotes ^= 2;
		else if (line[i] == '\"' && !ft_is_escaped(line, i) && !single_quotes)
			double_quotes ^= 4;
		i++;
	}
	return (single_quotes ^ double_quotes);
}

int32_t	ft_is_line_backslash_terminated(char *line)
{
	uint32_t	len;

	len = ft_strlen(line);
	if (len)
		if (line[len - 1] == '\\' && !ft_is_quoted(line, len - 1))
		{
			line[len - 1] = '\0';
			return (1);
		}
	return (0);
}

void	ft_line_continuation_put_prompt(int32_t ret)
{
	if (ret >= 2)
		ft_putstr("dquote>");
	else if (ret == 1)
		ft_putstr("quote>");
	else
		ft_putstr(">");
}

char	*ft_line_continuation(char *line)
{
	int32_t		ret;
	char		*tmp;

	tmp = NULL;
	if ((ret = ft_is_unbalanced(line))
		|| ft_is_line_backslash_terminated(line))
	{
		ft_line_continuation_put_prompt(ret);
		while (get_next_line(0, &tmp) > 0)
		{
			ret = 0;
			line = ft_strjoin_f(line, tmp, 0);
			if (((ret = ft_is_unbalanced(line)) > 0)
				|| ft_is_line_backslash_terminated(line))
				ft_line_continuation_put_prompt(ret);
			else
				break ;
		}
	}
	return (line);
}
