/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 22:19:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/24 18:36:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t			ft_exec_pipeline(t_parser *parser, t_shenv *shenv)
{
	if (OR_PARSER_N(parser, 0)->retained)
		return (!ft_exec_pipe_sequence(AND_PARSER_N(OR_PARSER_N(parser
									, 0), 1), shenv));
	else
		return (ft_exec_pipe_sequence(OR_PARSER_N(parser, 1), shenv));
}

static void		ft_restore_fds(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(fd[2], STDERR_FILENO);
	close(fd[2]);
}

static void		ft_store_fds(int *restored_fds)
{
	restored_fds[0] = dup(STDIN_FILENO);
	restored_fds[1] = dup(STDOUT_FILENO);
	restored_fds[2] = dup(STDERR_FILENO);
}

static int32_t	ft_launch_pipe_job(t_process **processes)
{
	int	ret;

	ft_put_processes_in_foreground(*processes, 1);
	waitpid((*processes)->gpid, &ret, WUNTRACED);
	ft_clear_processes(processes);
	ft_put_shell_in_foreground();
	return (POSIX_EXIT_STATUS(ret));
}

int32_t			ft_exec_pipe_sequence(t_parser *parser, t_shenv *shenv)
{
	int			restored_fds[3];
	t_process	*processes;
	int			ret;

	if (IS_RETAINED(OR_PARSER_N(parser, 1)))
	{
		parser = OR_PARSER_N(parser, 1);
		ft_store_fds(restored_fds);
		if (!(ft_is_built_in(parser) || IS_RETAINED(OR_PARSER_N(parser, 1))))
		{
			processes = ft_start_process(parser, 0, (int[]){0, 1, 0, 1}, shenv);
			ret = ft_launch_pipe_job(&processes);
			shenv->heredocs_index += ft_get_cmd_heredoc_count(parser);
		}
		else
			ret = ft_exec_simple_cmd(parser, shenv);
		ft_restore_fds(restored_fds);
	}
	else
	{
		parser = OR_PARSER_N(parser, 0);
		processes = ft_create_pipeline(parser, shenv);
		ret = ft_launch_pipe_job(&processes);
	}
	return (POSIX_EXIT_STATUS(ret));
}
