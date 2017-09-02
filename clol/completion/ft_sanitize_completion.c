/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitize_completion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 00:16:38 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 07:12:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_completion.h"

static void	normilol(char **completion, char *tmp)
{
	uint32_t	i;
	uint32_t	u;

	i = 0;
	u = 0;
	while (completion[0][i])
	{
		if (ft_strchr("|&;<>()$`\"' \t\n", completion[0][i]))
		{
			tmp[u++] = '\\';
			tmp[u] = completion[0][i];
		}
		else
			tmp[u] = completion[0][i];
		i++;
		u++;
	}
}

void		ft_sanitize_completion(char **completion)
{
	char		*tmp;
	uint32_t	i;
	uint32_t	count;
	uint32_t	len;

	i = 0;
	count = 0;
	len = ft_strlen(*completion);
	while (completion[0][i])
	{
		if (ft_strchr("|&;<>()$`\"' \t\n", completion[0][i]))
			count++;
		i++;
	}
	if (!count)
		return ;
	if (!(tmp = ft_strnew(len + count)))
		exit(EXIT_FAILURE);
	normilol(completion, tmp);
	free(*completion);
	*completion = tmp;
}

void		ft_sanitize_completions(char **completions)
{
	uint32_t	i;

	i = 0;
	while (completions[i])
		ft_sanitize_completion(completions + i++);
}
