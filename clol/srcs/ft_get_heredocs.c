/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_heredocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:55:24 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/13 19:28:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_the_norme(int fd, char *heredoc_input, uint32_t offset)
{
	write(fd, heredoc_input, offset);
	if (close(fd) == -1)
		ft_error_exit(1, (char*[]){"Failed to close Here-Document file"}
					, EXIT_HEREDOC_FILE);
	free(heredoc_input);
}

static char	*ft_strjoin_f_safe(char *s1, char *s2, uint32_t flag)
{
	char	*tmp;

	if (!(tmp = ft_strjoin_f(s1, s2, flag)))
		exit(EXIT_FAILURE);
	return (tmp);
}

void		ft_get_heredoc(t_heredoc *heredoc, t_shenv *shenv)
{
	char		*heredoc_input;
	char		*tmp;
	int			fd;
	uint32_t	offset;

	if (!(fd = ft_open_heredoc_file(heredoc->filename)))
		return ;
	ft_set_and_put_prompt(HEREDOC_PROMPT);
	ft_termget(&heredoc_input, shenv);
	if (!(heredoc_input = ft_strdup(heredoc_input)))
		exit(EXIT_FAILURE);
	offset = 0;
	while (ft_strcmp(heredoc_input + offset, heredoc->delimiter))
	{
		heredoc_input = ft_strjoin_f_safe(heredoc_input, "\n", 0);
		offset += ft_strlen(heredoc_input + offset);
		ft_put_prompt();
		if ((ft_termget(&tmp, shenv)) == (uint32_t)-1)
			break ;
		if (!(ft_strcmp(tmp, heredoc->delimiter)))
			break ;
		heredoc_input = ft_strjoin_f_safe(heredoc_input, tmp, 0);
	}
	ft_get_the_norme(fd, heredoc_input, offset);
}

void		ft_get_heredocs(t_shenv *shenv)
{
	t_heredoc	*tmp;
	uint32_t	i;
	uint32_t	len;

	i = 0;
	if (shenv->heredocs)
		len = ft_lstlen(shenv->heredocs);
	else
		return ;
	while (i < len)
	{
		tmp = ft_get_heredoc_pointer(i, shenv);
		ft_get_heredoc(tmp, shenv);
		i++;
	}
}
