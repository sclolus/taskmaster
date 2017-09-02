/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredocs_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:51:35 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 07:03:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_open_heredoc_redirec(int32_t redirect_fd
									, t_heredoc *heredocument)
{
	int32_t	fd_file;

	if ((fd_file = ft_open_heredoc_file(heredocument->filename)) == -1)
		ft_error_exit(1, (char*[]){"Failed to open heredoc"}
				, EXIT_REDIREC_ERROR);
	if (dup2(fd_file, redirect_fd) == -1)
		ft_error_exit(1, (char*[]){"File descriptor duplication failed"}
				, EXIT_REDIREC_ERROR);
	close(fd_file);
}

int32_t		ft_heredoc_redirect(t_parser *heredoc)
{
	int32_t		redirect_fd;
	t_shenv		*shenv;
	t_heredoc	*heredocument;

	shenv = *ft_get_shenv();
	if (!(heredocument = ft_get_t_heredoc_index(shenv->heredocs_index, shenv)))
		return (EXIT_REDIREC_ERROR);
	shenv->heredocs_index++;
	if (OR_PARSER_N(heredoc, 0)->retained)
	{
		heredoc = OR_PARSER_N(heredoc, 0);
		redirect_fd = ft_atoi(AND_PARSER_N(heredoc, 0)->parser.str_any_of.str);
		if (redirect_fd < 0)
			ft_error_exit(1, (char*[]){ERROR_BAD_FD}, EXIT_REDIREC_ERROR);
		ft_open_heredoc_redirec(redirect_fd, heredocument);
	}
	else
	{
		heredoc = OR_PARSER_N(heredoc, 1);
		redirect_fd = STDIN_FILENO;
		ft_open_heredoc_redirec(redirect_fd, heredocument);
	}
	return (redirect_fd);
}
