/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_deamon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:22:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 19:22:09 by sclolus          ###   ########.fr       */
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
		/*
		  chdir("/");
		  if (-1 ==  close(STDIN_FILENO) || -1 == close(STDERR_FILENO)
		  || -1 == close(STOUT_FILENO))
		  {
		  perror(DEAMON_NAME);
		  ft_log(1, (char*[]){"Fail to close standard i/o"});
		  exit(EXIT_FAILURE);
		  }
		  umask(0);
		 */
		if (-1 == (pid = fork()))
			ft_error_exit(1, (char*[]){"Failed to fork the deamon"}, EXIT_FAILURE);
		else if (pid)
			exit(EXIT_SUCCESS);
		else
			return ;
	}
}
