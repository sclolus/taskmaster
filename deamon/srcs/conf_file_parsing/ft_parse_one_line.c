/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_one_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:23:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:17:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

inline int32_t	ft_parse_one_line(char *line, uint32_t index
						, t_supervised_program *prog)
{
	static t_conf_parsing_state	parsing_machine[] =
	{
		{NULL, ft_is_prog_name_case, ft_get_prog_name},
		{"		cmd:", NULL, ft_get_cmd},
		{"		numprocs:", NULL, ft_get_nbr_procs},
		{"		workingdir:", NULL, ft_get_working_dir},
		{"		autorestart:", NULL, ft_get_autorestart},
		{"		autostart:", NULL, ft_get_autostart},
		{"		exitcodes:", NULL, NULL /*ft_get_exit_status*/},
		{"		startretries:", NULL, ft_get_start_retries},
		{"		starttime:", NULL, ft_get_start_time},
		{"		stopsignal:", NULL, ft_get_stop_signal},
		{"		stoptime:", NULL, ft_get_stop_time},
		{"		stdout:", NULL, ft_get_stdout_redirec},
		{"		stderr:", NULL, ft_get_stderr_redirec},
		{"		env:", NULL, NULL/*ft_get_env*/},
		{"		umask:", NULL, NULL/*ft_get_umask*/}};
	uint32_t					i;

	i = 0;
	while (i < sizeof(parsing_machine) / sizeof(t_conf_parsing_state))
	{
		if (parsing_machine[i].id)
		{
			if (ft_strnequ(line, parsing_machine[i].id, ft_strlen(parsing_machine[i].id)))
				return (parsing_machine[i].f_action(line, index, prog));
		}
		else if (parsing_machine[i].f_case(line, index, prog))
			return (parsing_machine[i].f_action(line, index, prog));
		i++;
	}
	return (0);
}
