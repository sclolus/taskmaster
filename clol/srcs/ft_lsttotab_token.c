/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:14:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 04:54:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_lsttotab_token(t_list *lst, unsigned int len)
{
	unsigned char	*tab;
	unsigned int	i;
	unsigned int	u;

	i = 0;
	u = 0;
	if (!(tab = (unsigned char*)malloc(sizeof(char*) * len)))
		return (0);
	while (i < len)
	{
		while (u < sizeof(char*))
		{
			tab[i * sizeof(char*) + u] = *((unsigned char*)&lst->content + u);
			u++;
		}
		u = 0;
		lst = lst->next;
		i++;
	}
	return (tab);
}
