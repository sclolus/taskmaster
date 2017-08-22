/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stderr_redirec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:54:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:14:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_get_stderr_redirec(char *line, uint32_t index
						, t_supervised_program *prog)
{
	index = ft_skip_cmd_header(line, index);
	prog->io_redirections.err = ft_get_parsing_path(line, index);
	return (1);
}
