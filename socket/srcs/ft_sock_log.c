/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 02:02:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 03:02:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_socket.h"

inline int32_t ft_sock_log(uint32_t n, const char **str
						   , int32_t return_status, t_connection connection)
{
	uint32_t	i;

	i = 0;
	while (i < n)
	{
		ft_putstr_fd(str[i], connection.fd);
		i++;
	}
	ft_putstr_fd("\n", connection.fd);
	return (return_status);
}
