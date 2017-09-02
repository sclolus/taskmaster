/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansions_io_redirect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 07:44:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/15 10:23:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expansions_io_filename(t_parser *io_filename, t_shenv *shenv)
{
	ft_tilde_expansion(&(AND_PARSER_N(io_filename
									, 1)->parser.str_any_of.str), shenv);
	ft_last_return_value_expansion(&(AND_PARSER_N(io_filename
									, 1)->parser.str_any_of.str));
	ft_var_expansion(&(AND_PARSER_N(io_filename
									, 1)->parser.str_any_of.str), shenv);
	ft_quote_removal(&(AND_PARSER_N(io_filename
									, 1)->parser.str_any_of.str));
}

void	ft_expansions_io_number(t_parser *io_number, t_shenv *shenv)
{
	ft_tilde_expansion(&(io_number->parser.str_any_of.str), shenv);
	ft_last_return_value_expansion(&(io_number->parser.str_any_of.str));
	ft_var_expansion(&(io_number->parser.str_any_of.str), shenv);
	ft_quote_removal(&(io_number->parser.str_any_of.str));
}

void	ft_expansions_io_file(t_parser *io_file, t_shenv *shenv)
{
	if (io_file->parser.or.matched == 1 || io_file->parser.or.matched == 3)
		ft_expansions_io_number(AND_PARSER_N(OR_PARSER_N(io_file
					, io_file->parser.or.matched), 2), shenv);
	else
		ft_expansions_io_filename(AND_PARSER_N(OR_PARSER_N(io_file
					, io_file->parser.or.matched), 1), shenv);
}

void	ft_expansions_io_redirect(t_parser *io_redirect, t_shenv *shenv)
{
	if (IS_RETAINED(OR_PARSER_N(io_redirect, 0)))
	{
		io_redirect = OR_PARSER_N(io_redirect, 0);
		ft_expansions_io_number(AND_PARSER_N(io_redirect, 0), shenv);
		ft_expansions_io_file(AND_PARSER_N(io_redirect, 1), shenv);
	}
	else
	{
		io_redirect = OR_PARSER_N(io_redirect, 1);
		ft_expansions_io_file(io_redirect, shenv);
	}
}
