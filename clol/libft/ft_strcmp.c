/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:38:56 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/06 16:46:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == *s2 && *s1)
		return (ft_strcmp((char*)s1 + 1, (char*)s2 + 1));
	else
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
