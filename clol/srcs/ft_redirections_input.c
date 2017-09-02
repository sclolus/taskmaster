/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:08:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/28 18:08:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_open_input_redirect(int32_t redirect_fd
									, char *filename)
{
	int32_t	fd_file;

	if ((fd_file = open(filename, O_RDONLY)) == -1)
		ft_error_exit(2, (char*[]){ERR_NOFILE
					, filename}, EXIT_REDIREC_ERROR);
	if (dup2(fd_file, redirect_fd) == -1)
		ft_error_exit(1, (char*[]){ERROR_BAD_FD}, EXIT_REDIREC_ERROR);
	close(fd_file);
}

int32_t			ft_input_redirect(t_parser *redirect)
{
	int32_t	redirect_fd;
	char	*filename;

	if (OR_PARSER_N(redirect, 0)->retained)
	{
		redirect = OR_PARSER_N(redirect, 0);
		redirect_fd = ft_atoi(AND_PARSER_N(redirect, 0)->parser.str_any_of.str);
		filename = AND_PARSER_N(AND_PARSER_N(OR_PARSER_N(AND_PARSER_N(redirect
							, 1), 2), 1), 1)->parser.str_any_of.str;
		if (redirect_fd < 0)
			ft_error_exit(1, (char*[]){"Invalid File descriptor"}
							, EXIT_REDIREC_ERROR);
		ft_open_input_redirect(redirect_fd, filename);
	}
	else
	{
		redirect = OR_PARSER_N(redirect, 1);
		redirect_fd = STDIN_FILENO;
		filename = AND_PARSER_N(AND_PARSER_N(OR_PARSER_N(
							redirect, 2), 1), 1)->parser.str_any_of.str;
		ft_open_input_redirect(redirect_fd, filename);
	}
	return (redirect_fd);
}

static void		ft_open_read_write_redirect(int32_t redirect_fd
									, char *filename)
{
	int32_t	fd_file;

	if ((fd_file = open(filename, O_RDWR | O_CREAT
						, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		ft_error_exit(2, (char*[]){ERR_NOFILE
					, filename}, EXIT_REDIREC_ERROR);
	if (dup2(fd_file, redirect_fd) == -1)
		ft_error_exit(1, (char*[]){ERROR_BAD_FD}, EXIT_REDIREC_ERROR);
	close(fd_file);
}

int32_t			ft_read_write_redirect(t_parser *redirect)
{
	int32_t	redirect_fd;
	char	*filename;

	if (OR_PARSER_N(redirect, 0)->retained)
	{
		redirect = OR_PARSER_N(redirect, 0);
		redirect_fd = ft_atoi(AND_PARSER_N(redirect, 0)->parser.str_any_of.str);
		filename = AND_PARSER_N(AND_PARSER_N(OR_PARSER_N(AND_PARSER_N(redirect
								, 1), 5), 1), 1)->parser.str_any_of.str;
		if (redirect_fd < 0)
			ft_error_exit(1, (char*[]){"Invalid File descriptor"}
								, EXIT_REDIREC_ERROR);
		ft_open_read_write_redirect(redirect_fd, filename);
	}
	else
	{
		redirect = OR_PARSER_N(redirect, 1);
		redirect_fd = STDIN_FILENO;
		filename = AND_PARSER_N(AND_PARSER_N(OR_PARSER_N(redirect, 5), 1)
								, 1)->parser.str_any_of.str;
		ft_open_read_write_redirect(redirect_fd, filename);
	}
	return (redirect_fd);
}
