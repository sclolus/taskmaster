/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 22:18:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/15 10:08:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t	ft_exec_command(t_parser *parser, t_shenv *shenv)
{
	if (IS_RETAINED(parser))
		return (ft_exec_list(AND_PARSER_N(parser, 1), shenv));
	else
		return (1);
}

int32_t	ft_exec_list(t_parser *parser, t_shenv *shenv)
{
	uint32_t	i;
	uint32_t	n;

	if (IS_RETAINED(OR_PARSER_N(parser, 1)))
	{
		parser = OR_PARSER_N(parser, 1);
		i = 0;
		n = PLUS_N(parser);
		while (i < n)
			ft_exec_and_or(AND_PARSER_N(PLUS_PARSER_N(parser
														, i++), 0), shenv);
		return (1);
	}
	else
	{
		parser = OR_PARSER_N(parser, 0);
		i = 0;
		n = MULTIPLY_N(AND_PARSER_N(parser, 0));
		while (i < n)
			ft_exec_and_or(AND_PARSER_N(MULTIPLY_PARSER_N(AND_PARSER_N(parser,
												0), i++), 0), shenv);
		ft_exec_and_or(AND_PARSER_N(parser, 1), shenv);
		return (1);
	}
}

int32_t	ft_exec_and_or(t_parser *parser, t_shenv *shenv)
{
	uint32_t	i;
	uint32_t	n;
	uint32_t	ret;

	i = 0;
	n = PLUS_N(parser);
	while (i < n)
	{
		if (OR_PARSER_N(PLUS_PARSER_N(parser, i), 0)->retained && !ret)
			ret = ft_exec_pipeline(AND_PARSER_N(OR_PARSER_N(
				PLUS_PARSER_N(parser, i), 0), 3), shenv);
		else if (OR_PARSER_N(PLUS_PARSER_N(parser, i), 1)->retained && ret)
			ret = ft_exec_pipeline(AND_PARSER_N(OR_PARSER_N(
				PLUS_PARSER_N(parser, i), 1), 3), shenv);
		else if (OR_PARSER_N(PLUS_PARSER_N(parser, i), 2)->retained)
			ret = ft_exec_pipeline(AND_PARSER_N(OR_PARSER_N(
				PLUS_PARSER_N(parser, i), 2), 1), shenv);
		*ft_get_last_return_value() = ret;
		i++;
	}
	return (ret);
}
