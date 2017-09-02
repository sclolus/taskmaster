/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_completions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:13:49 by aalves            #+#    #+#             */
/*   Updated: 2017/05/15 10:02:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		initlol(uint32_t *a, uint32_t *b, uint32_t *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

char			**ft_get_completions(char **tab, char *to_complete)
{
	char		*pathname;
	char		*filename;
	uint32_t	i;
	uint32_t	count;
	uint32_t	offset;

	initlol(&i, &count, &offset);
	if (!tab || !to_complete || !(filename = ft_get_file_name(to_complete)))
		return (NULL);
	if ((pathname = ft_get_path_name(to_complete)) && *ft_get_term_state() != 2)
		offset = ft_strlen(pathname);
	while (tab[i])
	{
		if (ft_strstr(tab[i] + offset, filename) == tab[i] + offset)
		{
			if (!(tab[count] = ft_strdup(tab[i] + offset)))
				exit(EXIT_FAILURE);
			count++;
		}
		i++;
	}
	tab[count] = NULL;
	return (tab);
}
