/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_status_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:51:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 10:55:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

const char	*ft_get_status_str(t_instance_status status)
{
	const static char	*status_strings[] = {"Error", "Working"
									, "Terminated", "Suspended"};
	return (status_strings[status]);
}
