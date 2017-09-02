/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 03:06:31 by jaustry           #+#    #+#             */
/*   Updated: 2017/05/14 05:28:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLETION_H
# define FT_COMPLETION_H
# include "libft.h"
# include <dirent.h>
# include "minishell.h"

char		**ft_get_matching_filenames(char *prefix);

/*
** Sanitization of completions
*/

void		ft_sanitize_completion(char **completion);
void		ft_sanitize_completions(char **completions);

void		ft_fuk_norminette(char **tmp, struct dirent *curr_entry
							, char *filename);
uint32_t	*ft_fuk_norminette2(char **completions, uint32_t n,
							t_string *buf, int64_t *old_offset);

#endif
