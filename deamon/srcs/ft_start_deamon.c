/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_deamon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:22:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 14:37:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

void	ft_start_deamon(void)
{
	pid_t	pid;

	if (-1 == (pid = fork()))
		ft_error_exit(1, (char*[]){"Failed to fork the deamon"}, EXIT_FAILURE);
	else if (pid)
		exit(EXIT_SUCCESS);
	else
	{
		setsid();
		return ;
	}
}
