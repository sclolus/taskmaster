/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termgets_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:23:54 by aalves            #+#    #+#             */
/*   Updated: 2017/05/19 01:06:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "minishell.h"

void		ft_append_line(char **line, char **final, uint32_t type)
{
	if (!*final)
	{
		if (!(*final = ft_strdup(*line)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (type)
		{
			if (!(*final = ft_strjoin_f(*final, "\n", 0)))
				exit(EXIT_FAILURE);
			if (!(*final = ft_strjoin_f(*final, *line, 0)))
				exit(EXIT_FAILURE);
		}
		else
		{
			if (!(*final = ft_strjoin_f(*final, *line, 0)))
				exit(EXIT_FAILURE);
		}
	}
}

int32_t		ft_term_line_continuation2(int32_t ret)
{
	if (ret >= 4)
	{
		ft_set_and_put_prompt(DOUBLE_QUOTE);
		return (ret);
	}
	else if (ret == 2)
	{
		ft_set_and_put_prompt(SINGLE_QUOTE);
		return (ret);
	}
	return (-1);
}
