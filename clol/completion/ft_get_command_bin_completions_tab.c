/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_bin_completions_tab.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 01:30:31 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 06:37:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_put_lst(t_list *lst)
{
	ft_putendl("___LIST___");
	while (lst)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
	ft_putendl("___END_LIST___");
}

static void	add_path(t_list **list, char *path, char *command_prefix)
{
	char	*tmp;
	t_list	*lst;

	if (!(tmp = ft_strjoin(path, "/")))
		exit(EXIT_FAILURE);
	if (!(tmp = ft_strjoin_f(tmp, command_prefix, 0)))
		exit(EXIT_FAILURE);
	if ((lst = ft_completion_add_directory_bin(tmp)))
		ft_merge_lists(list, lst);
	free(tmp);
}

char		**ft_get_command_bin_completions_tab(char *command_prefix,
														char **path)
{
	char		**tab;
	t_list		*path_lst;
	uint32_t	i;

	i = 0;
	path_lst = NULL;
	while (path[i])
		add_path(&path_lst, path[i++], command_prefix);
	tab = ft_lsttotab_completion(path_lst);
	tab = ft_get_completions(tab, command_prefix);
	ft_free_completions_lst(path_lst);
	return (tab);
}
