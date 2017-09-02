/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredocs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:55:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/09 03:37:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_create_heredoc_file(char *delimiter
								, uint32_t index, t_shenv *shenv)
{
	char		*filename;
	t_heredoc	*new_heredoc;
	t_list		*lstnew;
	int			fd;

	if (!(filename = ft_strjoin_f("/tmp/", ft_itoa(index), 1)))
		exit(EXIT_FAILURE);
	if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC
					, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		ft_error_exit(1, (char*[]){"Failed to create Here-Document File"}
					, EXIT_HEREDOC_FILE);
	close(fd);
	if (!(lstnew = ft_lstnew(0, 0)))
		exit(EXIT_FAILURE);
	if (!(new_heredoc = (t_heredoc*)ft_memalloc(sizeof(t_heredoc))))
		exit(EXIT_FAILURE);
	lstnew->content = new_heredoc;
	new_heredoc->filename = filename;
	new_heredoc->delimiter = delimiter;
	ft_lstadd(&shenv->heredocs, lstnew);
	return (filename);
}

int		ft_open_heredoc_file(char *filename)
{
	int			fd;

	if ((fd = open(filename, O_RDWR)) == -1)
		ft_error_exit(1, (char*[]){"Failed to open Here-Document File"}
					, EXIT_HEREDOC_FILE);
	if (fd < 0)
		ft_error_exit(1, (char*[]){"Bad file descriptor"}, -1);
	return (fd);
}

void	ft_create_heredocs(t_tokens *tokens, t_shenv *shenv)
{
	char		*delimiter;
	uint32_t	count;

	count = 0;
	while (42)
	{
		if (!(delimiter = ft_get_heredoc_delimiter_index(tokens, count)))
			break ;
		ft_create_heredoc_file(delimiter, count, shenv);
		count++;
	}
	shenv->heredocs_index = 0;
}
