/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_t_supervised_program.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 19:25:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 19:56:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline static void	ft_print_supervised_program(t_supervised_program *prog)
{
	printf("Program_name: %s\n\tcmd: %s\n\tworking_dir: %s\n\tprocess_nbr: %u\n\tstart_retries: %u\n\tstart_time: %llu\n\tstop_time: %llu\n\tstop_signal: %d\n\tstdout: %s\n\tstderr: %s\n\tautostart: %hu\n\tautorestart: %hu", prog->name, prog->start_info.cmd, prog->start_info.working_dir, prog->start_info.process_nbr, prog->start_info.start_retries, prog->start_info.start_time, prog->start_info.stop_time, prog->start_info.stop_signal, prog->io_redirections.out, prog->io_redirections.err, prog->process_flags.bits.autostart, prog->process_flags.bits.autorestart);
}

void	ft_dump_t_supervised_program(t_list *programs)
{
	while (programs)
	{
		ft_print_supervised_program(((t_supervised_program*)programs->content));
		printf("\n\n");
		programs = programs->next;
	}
}
