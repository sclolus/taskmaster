/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_completion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:50:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/14 03:57:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t			ft_put_completion(char **completions,
									t_string *buf, char *prefix)
{
	uint32_t	i;
	uint32_t	n;

	n = 0;
	i = 0;
	if (!completions)
	{
		ft_putchar(7);
		return (0);
	}
	while (completions[n])
		n++;
	ft_put_max_completion(buf, completions, prefix, n);
	if (n > 1)
		ft_put_completions(buf, completions, n, prefix);
	return (1);
}

int32_t			ft_completion(t_string *buf, t_shenv *shenv)
{
	static const t_comp_event	events[] = {
		NULL,
		&ft_completion_normal_state,
		&ft_complete_command_name,
		&ft_complete_argv,
	};
	t_termcaps_state			*state;

	ft_set_term_state(buf);
	state = ft_get_term_state();
	return (events[*state](buf, shenv));
}
