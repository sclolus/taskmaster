/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_add_directory.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:13:44 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 06:25:24 by tamere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	make_name(char **tmp, char **tmp_curr_name,
			char *path, struct dirent *curr_entry)
{
	if (!(*tmp = ft_strjoin(path, curr_entry->d_name)))
		exit(EXIT_FAILURE);
	if (ft_is_dir(*tmp))
		(*tmp_curr_name = ft_strjoin(curr_entry->d_name, "/"))
		? 0 : exit(EXIT_FAILURE);
	else
		(*tmp_curr_name = ft_strdup(curr_entry->d_name))
		? 0 : exit(EXIT_FAILURE);
	if (!(*tmp_curr_name = ft_strjoin_f(path, *tmp_curr_name, 1)))
		exit(EXIT_FAILURE);
}

static void	list_insert(t_list **head, char *name)
{
	t_list			*lst;

	if (!(lst = ft_lstnew(0, 0)))
		exit(EXIT_FAILURE);
	lst->content = name;
	ft_lstadd(head, lst);
}

t_list		*ft_completion_add_directory(char *path)
{
	DIR				*curr_dir;
	struct dirent	*curr_entry;
	char			*tmp;
	char			*tmp_curr_name;
	t_list			*list_dir;

	list_dir = NULL;
	path = ft_get_path_name(path);
	if (!(curr_dir = opendir(!*path ? "." : path)))
		return (NULL);
	while ((curr_entry = readdir(curr_dir)))
	{
		if (!ft_strcmp(".", curr_entry->d_name) ||
				!ft_strcmp("..", curr_entry->d_name))
			continue;
		make_name(&tmp, &tmp_curr_name, path, curr_entry);
		list_insert(&list_dir, tmp_curr_name);
		free(tmp);
	}
	if (closedir(curr_dir) == -1)
		ft_error_exit(1, (char*[]){"Failed to close completion directory"}, 4);
	return (list_dir);
}
