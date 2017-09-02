/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_duplicating.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:07:44 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/28 18:10:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_duplicate_input_redirect(char *word, int32_t redirect_fd)
{
	int32_t	fd_duplicated;

	if (!(ft_strcmp(word, "-")))
	{
		close(redirect_fd);
		return ;
	}
	if ((fd_duplicated = ft_atoi(word)) < 0)
		ft_error_exit(1, (char*[]){"file number expected"}, EXIT_REDIREC_ERROR);
	if (redirect_fd < 0)
		ft_error_exit(1, (char*[]){"Invalid File descriptor"}
							, EXIT_REDIREC_ERROR);
	if (dup2(fd_duplicated, redirect_fd) == -1)
		ft_error_exit(1, (char*[]){ERROR_BAD_FD}, EXIT_REDIREC_ERROR);
}

int32_t			ft_duplicating_input_redirect(t_parser *redirect)
{
	int32_t	redirect_fd;

	if (OR_PARSER_N(redirect, 0)->retained)
	{
		redirect = OR_PARSER_N(redirect, 0);
		redirect_fd = ft_atoi(AND_PARSER_N(redirect, 0)->parser.str_any_of.str);
		ft_duplicate_input_redirect(AND_PARSER_N(OR_PARSER_N(AND_PARSER_N(
		redirect, 1), 3), 2)->parser.str_any_of.str, redirect_fd);
	}
	else
	{
		redirect = OR_PARSER_N(redirect, 1);
		redirect_fd = STDIN_FILENO;
		ft_duplicate_input_redirect(AND_PARSER_N(OR_PARSER_N(
						redirect, 3), 2)->parser.str_any_of.str, redirect_fd);
	}
	return (redirect_fd);
}

static void		ft_duplicate_output_redirect(char *word, int32_t redirect_fd)
{
	int32_t	fd_duplicated;

	if (!(ft_strcmp(word, "-")))
	{
		close(redirect_fd);
		return ;
	}
	if ((fd_duplicated = ft_atoi(word)) < 0)
		ft_error_exit(1, (char*[]){"file number expected"}, EXIT_REDIREC_ERROR);
	if (redirect_fd < 0)
		ft_error_exit(1, (char*[]){"Invalid File descriptor"}
							, EXIT_REDIREC_ERROR);
	if (dup2(fd_duplicated, redirect_fd) == -1)
		ft_error_exit(1, (char*[]){ERROR_BAD_FD}, EXIT_REDIREC_ERROR);
}

int32_t			ft_duplicating_output_redirect(t_parser *redirect)
{
	int32_t	redirect_fd;

	if (OR_PARSER_N(redirect, 0)->retained)
	{
		redirect = OR_PARSER_N(redirect, 0);
		redirect_fd = ft_atoi(AND_PARSER_N(redirect, 0)->parser.str_any_of.str);
		ft_duplicate_output_redirect(AND_PARSER_N(OR_PARSER_N(AND_PARSER_N(
				redirect, 1), 1), 2)->parser.str_any_of.str, redirect_fd);
	}
	else
	{
		redirect = OR_PARSER_N(redirect, 1);
		redirect_fd = STDOUT_FILENO;
		ft_duplicate_output_redirect(AND_PARSER_N(OR_PARSER_N(redirect, 1)
							, 2)->parser.str_any_of.str, redirect_fd);
	}
	return (redirect_fd);
}
