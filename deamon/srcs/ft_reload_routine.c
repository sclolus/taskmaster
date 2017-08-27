/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 02:43:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 03:04:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_reload_routine(t_supervised_program *prog, int fds[2])
{
	char	message;

	message = RELOAD_FORK_SUCCESS;
	ft_log(2, (const char*[]){"Cleaned current process:", prog->name}); // pid ?
	write(fds[1], &message, 1);
	ft_stop_process(prog);
}
