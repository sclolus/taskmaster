/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_task_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 04:06:43 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/16 04:14:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline void	ft_task_request(t_control_info *control_info, uint8_t task)
{
	write(control_info->fd[1], &(uint8_t){task}, 1);
	kill(control_info->pid, SIGUSR1);
}
