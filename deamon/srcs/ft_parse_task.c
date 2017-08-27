/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_task.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 23:30:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/27 01:22:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deamon.h"

static inline int32_t				ft_check_proc_num_format(
									char *proc_num_str)
{
	uint32_t	i;

	i = 0;
	if (*proc_num_str == '%')
	{
		while (proc_num_str[i])
		{
			if (!ft_isdigit(proc_num_str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

static inline uint32_t				ft_is_valid_proc_num(char *proc_num_str
												, t_supervised_program *prog)
{
	uint32_t	proc_num;

	proc_num = (uint32_t)ft_atoi(proc_num_str + 1);
	if (proc_num < prog->start_info.process_nbr)
		return (proc_num);
	return (~0U);
}

static inline t_supervised_program	*ft_is_valid_prog_name(char *name
												, t_list *progs)
{
	while (progs)
	{
		if (ft_strequ(name, ((t_supervised_program*)progs->content)->name))
			return (((t_supervised_program*)progs->content));
		progs = progs->next;
	}
	return (NULL);
}

static void							ft_cleanup_argv(char ***argv)
{
	uint32_t	i;

	i = 0;
	if (*argv)
	{
		while ((*argv)[i])
			free((*argv)[i++]);
		free((*argv));
	}
}

int32_t								ft_parse_task(char *task, t_list *progs
							, t_supervised_program **prog, uint32_t *proc_num)
{
	char					**argv __attribute__((cleanup(ft_cleanup_argv)));
	uint32_t				i;

	if (!(argv = ft_strsplit(task, ' ')))
		ft_error_exit(2, (char*[]){MALLOC_FAILURE, "ft_parse_task()"}
	, EXIT_FAILURE);
	i = 0;
	*proc_num = 0;
	while (argv[i])
		i++;
	if (i == 1)
		return (0);
	if (!(*prog = ft_is_valid_prog_name(argv[1], progs)))
	{
		ft_sock_send("Invalid program name\n", g_connection->fd);
		return (0);
	}
	if (i == 3)
	{
		if (ft_check_proc_num_format(argv[2])
			|| ~0U == (*proc_num = ft_is_valid_proc_num(argv[2], *prog)))
		{
			ft_sock_send("Invalid process number provided\n", g_connection->fd);
			return (0);
		}
	}
	return (1);
}
