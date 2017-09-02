/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_completion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:14:02 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 00:14:03 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_max_completion(char **tab, char *to_complete)
{
	char		*max_completion;
	uint32_t	len;
	uint32_t	max_offset;
	uint32_t	tmp;
	uint32_t	i;

	max_offset = ~0;
	i = 0;
	while (tab[i])
	{
		tmp = ft_get_max_common_len(tab[0], tab[i]);
		if (tmp < max_offset)
			max_offset = tmp;
		i++;
	}
	if (max_offset == ~0U || !max_offset || !tab[0])
		return (NULL);
	len = ft_strlen(ft_get_file_name(to_complete));
	max_offset -= len;
	if (!(max_completion = ft_strndup(tab[0] + len
							, max_offset)))
		exit(EXIT_FAILURE);
	return (max_completion);
}
