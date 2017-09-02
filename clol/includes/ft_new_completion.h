/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_completion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:14:25 by aalves            #+#    #+#             */
/*   Updated: 2017/05/14 00:15:11 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NEW_COMPLETION_H
# define FT_NEW_COMPLETION_H

# include "minishell.h"

char		*ft_get_max_completion(char **tab, char *to_complete);
uint32_t	ft_get_max_common_len(char *s1, char *s2);
char		**ft_get_completions(char **tab, char *to_complete);
char		**ft_lsttotab_completion(t_list *lst);
t_list		*ft_completion_add_directory(char *path);
t_list		*ft_completion_add_directory_bin(char *path);
char		**ft_get_completions_tab(char *command_prefix);
char		**ft_get_command_directory_completions_tab(char *command_prefix);
void		ft_merge_lists(t_list **a, t_list *b);
char		**ft_get_command_bin_completions_tab(char *command_prefix,
														char **path);
void		ft_free_completions_lst(t_list *lst);
void		ft_free_completion_tab(char **tab);

#endif
