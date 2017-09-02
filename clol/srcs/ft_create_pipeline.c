/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 00:10:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 07:20:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_assign_stacked_pipes(int *mypipe, int *curr_stdout
										, uint32_t i, t_parser *pipe_sequence)
{
	if (i == MULTIPLY_N(AND_PARSER_N(pipe_sequence, 0)) - 1)
	{
		*curr_stdout = mypipe[4];
		mypipe[3] = 1;
	}
	else if (pipe(mypipe) == -1)
		ft_error_exit(1, (char*[]){"Pipe() failed"}, EXIT_REDIREC_ERROR);
	else
	{
		*curr_stdout = mypipe[1];
		mypipe[3] = mypipe[0];
	}
}

static void			ft_get_pipes(t_parser *pipe_sequence, int *mypipe
								, t_process **processes, t_shenv *shenv)
{
	pid_t		pipeline_pgid;
	uint32_t	i;
	int			curr_stdin;
	int			curr_stdout;

	i = 0;
	curr_stdin = 0;
	pipeline_pgid = (*processes)->pid;
	while (i < MULTIPLY_N(AND_PARSER_N(pipe_sequence, 0)))
	{
		ft_assign_stacked_pipes(mypipe, &curr_stdout, i, pipe_sequence);
		ft_t_process_add(processes, ft_start_process(AND_PARSER_N(
			MULTIPLY_PARSER_N(AND_PARSER_N(pipe_sequence, 0), i), 0),
			pipeline_pgid, (int[]){curr_stdin, curr_stdout, mypipe[2],
			mypipe[3]}, shenv));
		shenv->heredocs_index += ft_get_cmd_heredoc_count(AND_PARSER_N(
					MULTIPLY_PARSER_N(AND_PARSER_N(pipe_sequence, 0), i), 0));
		i++;
		if (curr_stdin != STDIN_FILENO)
			close(curr_stdin);
		if (curr_stdout != STDOUT_FILENO)
			close(curr_stdout);
		curr_stdin = mypipe[0];
		mypipe[2] = mypipe[1];
	}
}

static void			ft_get_last_process_heredoc_index(t_parser *pipe_sequence
													, t_shenv *shenv)
{
	uint32_t	i;

	i = 0;
	while (i < MULTIPLY_N(AND_PARSER_N(pipe_sequence, 0)))
	{
		shenv->heredocs_index += ft_get_cmd_heredoc_count(AND_PARSER_N(
					MULTIPLY_PARSER_N(AND_PARSER_N(pipe_sequence, 0), i), 0));
		i++;
	}
}

t_process			*ft_create_pipeline(t_parser *pipe_sequence, t_shenv *shenv)
{
	t_process	*processes;
	pid_t		pipeline_pgid;
	uint32_t	index_tmp;
	int			mypipe[5];

	if (pipe(mypipe + 3) == -1)
		ft_error_exit(1, (char*[]){"Pipe() failed"}, EXIT_REDIREC_ERROR);
	index_tmp = shenv->heredocs_index;
	ft_get_last_process_heredoc_index(pipe_sequence, shenv);
	processes = ft_start_process(AND_PARSER_N(pipe_sequence, 1), 0,
									(int[]){mypipe[3], 1, mypipe[4], 1}, shenv);
	pipeline_pgid = processes->pid;
	mypipe[2] = 0;
	shenv->heredocs_index = index_tmp;
	ft_get_pipes(pipe_sequence, mypipe, &processes, shenv);
	shenv->heredocs_index += ft_get_cmd_heredoc_count(AND_PARSER_N(pipe_sequence
																, 1));
	return (processes);
}
