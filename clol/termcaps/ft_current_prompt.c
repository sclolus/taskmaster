/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 05:48:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 04:11:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

t_prompt_state	*ft_get_prompt_state_machine(void)
{
	static t_prompt_state	states[] = {
		{NORMAL_PROMPT_STATE, NORMAL_PROMPT_LEN},
		{S_QUOTE_PROMPT_STATE, S_QUOTE_PROMPT_LEN},
		{D_QUOTE_PROMPT_STATE, D_QUOTE_PROMPT_LEN},
		{LINE_CONT_PROMPT_STATE, LINE_CONT_PROMPT_LEN},
		{HEREDOC_CONT_PROMPT_STATE, HEREDOC_CONT_PROMPT_LEN},
	};

	return (states);
}

t_prompt		*ft_get_current_prompt(void)
{
	static t_prompt	current_prompt = NORMAL_PROMPT;

	return (&current_prompt);
}

void			ft_set_current_prompt(t_prompt new_prompt)
{
	*ft_get_current_prompt() = new_prompt;
}

void			ft_put_prompt(void)
{
	ft_putstr(ft_get_prompt_state_machine()[*ft_get_current_prompt()].prompt);
}

void			ft_set_and_put_prompt(t_prompt new_prompt)
{
	ft_set_current_prompt(new_prompt);
	ft_put_prompt();
}
