/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab_completion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:14:11 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 00:14:18 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_lsttotab_completion(t_list *lst)
{
	uint32_t	len;
	uint32_t	i;
	char		**tab;

	if (!lst)
		return (NULL);
	len = ft_lstlen(lst);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < len)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
	return (tab);
}
