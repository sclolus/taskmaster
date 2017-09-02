/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 02:11:54 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/20 02:14:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ft_free_argv() assumes that argv is a NULL-terminated array of strings
*/

void	ft_free_argv(char **argv)
{
	uint32_t	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
