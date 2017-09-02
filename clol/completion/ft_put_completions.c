/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_completions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:42:20 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/14 03:52:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_completion.h"

static void		ft_termcaps_go_back_to_offset(t_string *buf, int64_t old_offset)
{
	char	*res;

	while (buf->offset > 0 && buf->offset > old_offset)
	{
		buf->offset--;
		res = tgetstr("le", NULL);
		tputs(res, 1, &ft_putterm);
	}
}

int32_t			ft_put_max_completion(t_string *buf, char **completions
									, char *prefix, uint32_t n)
{
	char		*max_completion;

	if ((max_completion = ft_get_max_completion(completions, prefix)))
	{
		if (*max_completion)
		{
			ft_t_string_insert(buf, max_completion);
			ft_termcaps_putstr(buf, max_completion);
			free(max_completion);
			return (1);
		}
		else
			ft_putchar(7);
		free(max_completion);
		if (n < 2)
			return (1);
	}
	else
	{
		ft_putchar(7);
		return (0);
	}
	return (-1);
}

static void		ft_completions_cleanup(t_string *buf, int64_t old_offset,
											uint32_t *lens)
{
	ft_static_put("\n", 1, 0);
	ft_static_put(ft_get_current_prompt_string()
				, ft_get_current_prompt_len(), 0);
	ft_static_put(buf->string, buf->len, 0);
	ft_static_put(NULL, 0, STATIC_PUT_FLUSH);
	ft_termcaps_go_back_to_offset(buf, old_offset);
	free(lens);
}

int32_t			ft_put_completions(t_string *buf, char **completions,
									uint32_t n, char *prefix)
{
	static struct winsize	window;
	static char				buffer[1024];
	uint32_t				*lens;
	uint32_t				i_offset[2];
	int64_t					old_offset;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	if (!(i_offset[0] = 0) && !window.ws_col)
		return (0);
	if (!(i_offset[1] = 0) && buffer[0] == 0)
		ft_memset(buffer, ' ', 1023);
	lens = ft_fuk_norminette2(completions, n, buf, &old_offset);
	while (i_offset[0] < n)
	{
		if (*completions[i_offset[0]] == '.' && *prefix != '.' && ++i_offset[0])
			continue ;
		if ((i_offset[1] + lens[n]) / window.ws_col && !(i_offset[1] = 0))
			ft_static_put("\n", 1, 0);
		ft_static_put(completions[i_offset[0]], lens[i_offset[0]], 0);
		ft_static_put(buffer, lens[n] - lens[i_offset[0]++], 0);
		i_offset[1] += lens[n];
	}
	ft_completions_cleanup(buf, old_offset, lens);
	return (n);
}
