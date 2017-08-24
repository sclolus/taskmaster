/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_process_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:18:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/23 22:22:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

/*
** Should be used and inited only in a control fork
*/

void	ft_set_process_status(t_process_status init_status)
{
	*ft_get_process_status() = init_status;
}

inline t_process_status	*ft_get_process_status(void)
{
	static t_process_status	status;

	return (&status);
}
