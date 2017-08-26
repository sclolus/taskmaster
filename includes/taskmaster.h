/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmaster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:14:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/26 19:29:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASKMASTER_H
# define TASKMASTER_H

# include <sys/socket.h>
# include "ft_socket.h"
# include <stdint.h>
# include "libft.h"
# define ANYPORT 0

typedef struct	s_exit_status
{
	uint8_t		*exit_status;
	uint64_t	nbr_expected_exit_status;
}				t_exit_status;

typedef struct	s_flag16
{
	uint16_t	autostart : 1;
	uint16_t	autorestart : 1;
	uint16_t	bit2 : 1;
	uint16_t	bit3 : 1;
	uint16_t	bit4 : 1;
	uint16_t	bit5 : 1;
	uint16_t	bit6 : 1;
	uint16_t	bit7 : 1;
	uint16_t	bit8 : 1;
	uint16_t	bit9 : 1;
	uint16_t	bit10 : 1;
	uint16_t	bit11 : 1;
	uint16_t	bit12 : 1;
	uint16_t	bit13 : 1;
	uint16_t	bit14 : 1;
	uint16_t	bit15 : 1;
}				t_flag16;

typedef union	s_process_flags
{
	uint16_t	flags;
	t_flag16	bits;
}				t_process_flags;

typedef struct	s_start_info
{
	char			**cmd;
	char			*working_dir;
	uint32_t		process_nbr;
	uint32_t		start_retries;
	uint64_t		start_time;
	uint64_t		stop_time;
	int				stop_signal;
	mode_t			umask;
	char			pad[2];
}				t_start_info;

typedef struct	s_io_redirection
{
	char	*stdin;
	char	*out;
	char	*err;
}				t_io_redirection;

typedef struct	s_supervised_program
{
	char				*name;
	t_io_redirection	io_redirections;
	t_start_info		start_info;
	t_exit_status		expected_exit_status;
	t_process_flags		process_flags;
	char				pad[2];
	pid_t				pid;
	/* t_env */char				**env;
}				t_supervised_program;

void	ft_dump_t_supervised_program(t_list *programs);

#endif
