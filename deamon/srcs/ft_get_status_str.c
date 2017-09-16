/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_status_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:51:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 02:37:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

const char	*ft_get_status_str(t_instance_status status)
{
	const static char	*status_strings[] = {"Error", "Working", "Exited"
									, "Terminated", "Suspended"};

	return (status_strings[status]);
}
