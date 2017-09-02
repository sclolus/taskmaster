/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_string_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 01:24:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/03/30 03:03:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*ft_t_string_new(uint32_t capacity)
{
	t_string	*string;

	if (!(string = (t_string*)malloc(sizeof(t_string))))
		exit(EXIT_FAILURE);
	string->capacity = capacity;
	if (!(string->string = ft_strnew(capacity)))
		exit(EXIT_FAILURE);
	string->len = 0;
	return (string);
}
