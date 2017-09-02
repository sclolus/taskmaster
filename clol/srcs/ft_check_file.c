/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:19:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/08 15:28:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t	ft_check_exec_perm(char *pathname)
{
	struct stat	file_stats;

	if (stat(pathname, &file_stats) == -1)
		return (0);
	return ((file_stats.st_mode & S_IXUSR) != 0);
}

int32_t	ft_check_exec_read(char *pathname)
{
	uid_t		euid;
	struct stat	file_stats;

	euid = geteuid();
	if (stat(pathname, &file_stats) == -1)
		return (0);
	if (file_stats.st_uid == euid)
		return ((file_stats.st_mode & S_IRUSR) != 0);
	else
		return (0);
}

int32_t	ft_check_exec_write(char *pathname)
{
	uid_t		euid;
	struct stat	file_stats;

	euid = geteuid();
	if (stat(pathname, &file_stats) == -1)
		return (0);
	if (file_stats.st_uid == euid)
		return ((file_stats.st_mode & S_IWUSR) != 0);
	else
		return (0);
}

int32_t	ft_is_dir(char *pathname)
{
	struct stat	file_stats;

	if (stat(pathname, &file_stats) == -1)
		return (0);
	if ((file_stats.st_mode & S_IFDIR) != 0)
		return (1);
	else
		return (0);
}
