/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 02:43:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 02:48:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_reload_routine(t_supervised_program *prog, int fds[2])
{
	char	message;

	message = RELOAD_FORK_SUCCESS;
	ft_stop_process(prog);
	ft_log(2, (char*[]){"Cleaned current process:", prog->name}); // pid ?
	write(fds[1], &message, 1);
	exit(EXIT_SUCCESS);
}
