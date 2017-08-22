/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmaster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:14:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/22 18:13:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASKMASTER_H
# define TASKMASTER_H

# include <sys/socket.h>
# include <stdint.h>
# define ANYPORT 0

typedef struct	s_exit_status
{
	uint8_t		*exit_status;
	uint64_t	nbr_expected_exit_status;
}				t_exit_status;

typedef struct	s_flag16
{
	uint16_t	autostart;
	uint16_t	autorestart;
	uint16_t	bit2;
	uint16_t	bit3;
	uint16_t	bit4;
	uint16_t	bit5;
	uint16_t	bit6;
	uint16_t	bit7;
	uint16_t	bit8;
	uint16_t	bit9;
	uint16_t	bit10;
	uint16_t	bit11;
	uint16_t	bit12;
	uint16_t	bit13;
	uint16_t	bit14;
	uint16_t	bit15;
}				t_flag16;

typedef union	s_process_flags
{
	uint16_t	flags;
	t_flag16	bits;
}				t_process_flags;

typedef struct	s_start_info
{
	char			*cmd;
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
	t_start_info		start_info;
	t_process_flags		process_flags;
	t_io_redirection	io_redirections;
	t_exit_status		expected_exit_status;
//	t_env				*process_env;
}				t_supervised_program;

#endif
