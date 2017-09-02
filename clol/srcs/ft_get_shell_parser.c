/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shell_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 06:06:01 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/24 18:20:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_grammar_string(void)
{
	int			fd;
	int32_t		ret;
	static char	buf[2048];
	char		*string;

	if (-1 == (fd = open("includes/grammar.txt", O_RDONLY)))
		ft_error_exit(1, (char*[]){"Opening of grammar.txt failed"}, 1);
	ret = 0;
	if (!(string = ft_strnew(0)))
		exit(EXIT_FAILURE);
	while ((ret = read(fd, buf, 2047)) > 0)
	{
		buf[ret] = 0;
		if (!(string = ft_strjoin_f(string, buf, 0)))
			exit(EXIT_FAILURE);
	}
	close(fd);
	return (string);
}

t_parser	*ft_get_shell_parser(void)
{
	t_parser	*bnf_parser;
	t_parser	*shell_parser;
	char		*string;
	char		*tmp;

	bnf_parser = ft_get_parser_grammar();
	string = ft_get_grammar_string();
	if (ft_checksum(string) != GRAMMAR_CHECKSUM)
		ft_error_exit(1, (char*[]){"Checksum invalid for grammar.txt, nice try"}
									, 2);
	tmp = string;
	if (ft_eval_input(bnf_parser, &string))
		shell_parser = ft_get_grammar_syntax(bnf_parser);
	else
	{
		ft_error_exit(1, (char*[]){"Grammar evaluation failed"}, 3);
		exit(EXIT_FAILURE);
	}
	ft_free_parser(bnf_parser);
	free(tmp);
	ft_optimizer(shell_parser);
	if (!shell_parser)
		exit(EXIT_FAILURE);
	return (shell_parser);
}
